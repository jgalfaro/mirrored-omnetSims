function [txPSK numberOfSamples] = modulatePSK(byteStream, fs, fc, symbolsPerSecond)
%% PSK modulation 
% Adapted from Borowski's dissertation
% Version: March 31, 2014
% byteStream = modulating data
% fs = sample frequency (sps)
% fc = carrier frequency (in Hertz)
% symbolsPerSecond = symbol rate (in bauds)
    % Add one byte of 10101010 for training
    trainingByte = 170;
    byteStream = [trainingByte byteStream];
    
    % calculate length of modulating data (in bits)
    numberOfBytes = length(byteStream);
    bitsInByte = 8;
    numberOfBits = numberOfBytes * bitsInByte;
    
    % convert the input byte stream into a bit stream
    bitStream = zeros(1, numberOfBits);
    for i = 1:numberOfBytes
        byte = uint8(byteStream(i));
        for j = 1:bitsInByte
            bit = bitshift(bitand(byte, 128), -7);
            bitStream((i - 1) * bitsInByte + j) = bit;
            byte = bitshift(byte, 1);
        end
    end

    % calculate number of samples per bit
    samplesPerBit = floor(fs / symbolsPerSecond);
    % frequency of carrier (in Hertz)
    carrierFreq = fc;

    % tones for "0" and "1" (they are separeted by "symbol rate" Hertz)
    if (symbolsPerSecond < 500)
        chirpRange = [(carrierFreq - 500) (carrierFreq + 500)];
    else
        chirpRange = [(carrierFreq - symbolsPerSecond) (carrierFreq + symbolsPerSecond)];
    end
    packetChirp = chirp(chirpRange(1), chirpRange(2), fs, 0.05);
    guardTime = zeros(1, 0.01 * fs);

    % initialize to zeros vector of modulated signal samples
    tx = zeros(1, samplesPerBit * numberOfBits);
    t = 0.0;
    for i = 1:numberOfBits
        % offeset of current data bit in the output sample stream
        offset = samplesPerBit * (i-1);
        for j = 1:samplesPerBit
            % determine phase of modulated signal
            t = t + 2 * pi * carrierFreq / fs;
            % chop phase, if greater than pi
            if (t > pi)
                t = t - 2 * pi;
            end
            % determine value of sample
            if (bitStream(i) == 0) % bit is "1"
                tx(j + offset) = -cos(t);
            else % bit is "1"
                tx(j + offset) = cos(t);
            end
        end
        t = 0.0;
    end

    % txPSK = [guardTime real(packetChirp) guardTime tx];
    % From Michel: guardTime and packetChirp are omitted
    txPSK = tx;
    numberOfSamples = length(txPSK);