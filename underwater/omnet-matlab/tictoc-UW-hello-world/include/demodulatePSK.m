function rxPSK = demodulatePSK(packetWaveform, numberOfBytes, fs, fc, symbolsPerSecond)
    %% PSK demodulation using a correlation receiver
    % Adapted from Borowski's dissertation
    % Version: March 5, 2014
    % packetWaveform = samples of a modulated signal
    % fs = sample frequency (sps)
    % fc = carrier frequency (in Hertz)
    % symbolsPerSecond = symbol frequency (in bauds)
    
    % Add one for the first 10101010 byte, which is hidden to the user
    trainingByte = 170;
    bitsInByte = 8;
    byte = uint8(trainingByte);
    data = zeros(1, bitsInByte);
    for j = 1:bitsInByte
        bit = bitshift(bitand(byte, 128), -7);
        data(j) = bit;
        byte = bitshift(byte, 1);
    end

    numberOfBytes = numberOfBytes + 1;
    % calculate number of samples per bit
    samplesPerBit = floor(fs / symbolsPerSecond);
    % frequency of carrier (in Hertz)
    carrierFreq = fc;

    % From Michel: processing of packetChirp omitted
    %if (symbolsPerSecond < 500)
    %    chirpRange = [(carrierFreq - 500) (carrierFreq + 500)];
    %else
    %    chirpRange = [(carrierFreq - symbolsPerSecond) (carrierFreq + symbolsPerSecond)];
    %end
    %packetChirp = chirp(chirpRange(1), chirpRange(2), fs, 0.05);
    %guardTime = zeros(1, 0.01 * fs);
    numberOfBits = numberOfBytes * 8;
    
    %% Synchronize on packet chirp signals
    %prefixLength = length(packetChirp) + length(guardTime);
    %correlatedSamples = real(fftshift(xcorr(packetWaveform(1:prefixLength), conj(packetChirp))));
    %[~, maxIndex] = max(correlatedSamples);
    %len = length(correlatedSamples);
    %if (maxIndex > len/2)
    %    maxIndex = maxIndex - len;
    %end
    %start = maxIndex + prefixLength;
    %packetWaveform = packetWaveform(start:start+samplesPerBit * numberOfBits);

    %% Create reference signals, find best phase offset for first bit
    % generate the time instants of a bit
    t = 0:samplesPerBit-1;
    % reference signal for bit "0"
    psk0 = -cos(2 * pi * carrierFreq/fs * t);
    % reference signal for bit "1"
    psk1 =  cos(2 * pi * carrierFreq/fs * t);

    firstSymbol = packetWaveform(1:samplesPerBit);
    offset = 0;
    oldZ0 = -inf;
    oldZ1 = -inf;
    phi = 0;
    for i = 1:24
        if (data(1) == 1)
            one = firstSymbol .* psk1;
            z1 = (sum(one));
            if (z1 > oldZ1)
                oldZ1 = z1;
                offset = phi;
            end
            phi = phi + (2 * pi) / 24;
            psk1 = cos(2 * pi * carrierFreq/fs * t + phi);
        else
            zero = firstSymbol .* psk0;
            z0 = (sum(zero));
            if (z0 > oldZ0)
                oldZ0 = z0;
                offset = phi;
            end
            phi = phi + (2 * pi) / 24;
            psk0 = -cos(2 * pi * carrierFreq/fs * t + phi);
        end
    end

    psk0 = -cos(2 * pi * carrierFreq/fs * t + offset);
    psk1 =  cos(2 * pi * carrierFreq/fs * t + offset);

    %% Demodulate
    rxPSK = zeros(1, numberOfBits); % received data
    for i = 1:numberOfBits
        % take the samples for one bit
        rcv = packetWaveform((i-1)*samplesPerBit + 1:i*samplesPerBit);
        % determine correlation with ref signal for bit "0"
        zero = rcv .* psk0;
        % determine correlation with ref signal for bit "1"
        one = rcv .* psk1;
        z0 = (sum(zero));
        z1 = (sum(one));
        % most correlated determines bit value
        rxPSK(i) = (z1 > z0);
    end
    bitStream = rxPSK;
    
    %% Convert back into chars
    bitsInByte = 8;
    numberOfBytes = numberOfBits / bitsInByte;
    byteStream = zeros(1, numberOfBytes);
    for i = 1:numberOfBytes
        byte = uint8(0);
        for j = 1:bitsInByte
            bit = uint8(bitand(bitStream((i - 1) * bitsInByte + j), 1));
            byte = bitor(byte, bit);
            if (j < bitsInByte)
                byte = bitshift(byte, 1);
            end
        end
        byteStream(i) = byte;
    end

    rxPSK = byteStream(2:end);