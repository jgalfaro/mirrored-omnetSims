function [samples nr] = simulateChannel(signal, fs, sps, d, P)
    % Adapted from Borowski's dissertation
    % Version: May 6, 2014
    %%% Formal parameters
    % signal = samples of a modulated signal
    % fs = sampling rate
    % sps = symbol rate (in bauds)
    % d = distance (in km)
    % P = transmission power (in u Pa)    
   
    % Amplification according to transmission power
    samples = sqrt(2*P)*signal;
    
    %%% 1. attenuation 
    %
    % Geometry of propagation 1=cylindrical, 2=spherical, 1.5 practical
    k=1.5;
    % Conversion to the frequency domain
    % Determine the number of FFT bins
    n = 2^nextpow2(length(samples)); % Next power of 2 from length of samples
    Y = fft(samples,n); % /length(samples);
    % Generate the range of frequencies (in Hertz)
    f=[-n/2:n/2]./n*fs;
    
    % plot frequency-domain representation 
    % figure; subplot(3,1,1); plot(f,abs([Y(n/2+1:n),Y(1:n/2+1)]));
    
    % initiliaze attenuation array
    theAttenuation=zeros(1,n/2);
    % Attenuate the frequencies
    for i=1:n/2
        % determine absorption
        theAbsorption=absorption( i/1000 ); % input param in kHz
        % calculate and apply the attenuation (in linear form)
        theAttenuation(i)=A( theAbsorption, k, d );
        % attenuate the positive frequencies (i=1:1:NFFT/2)
        Y(i) = Y(i) / theAttenuation(i);
        % attenuate the negative frequencies (i=NFFT:-1:NFFT/2+1)
        Y(n-i+1) = Y(n-i+1) / theAttenuation(i);
    end
    
    % plot attenuation
    % subplot(3,1,2); plot(1:n/2,theAttenuation);  
    
    % plot frequency-domain representation after attenuation
    % subplot(3,1,3); plot(f,abs([Y(n/2+1:n),Y(1:n/2+1)]));
    
    % Re-conversion in the time domain
    samples = ifft(Y,n);  
    
    %%% 2. Colored noise insertion, according to equation N(f)db = 50 - 18*log f
    %
    % Voltage of noise
    VN = sqrt(2*power(10,32/10)*2*sps);
    % Generate the peak noise
    noise =  VN*randn(size(samples));
    % Color the noise
    colorednoise = mylowpassfilter(noise);
    % add the colored noise
    samples = samples + colorednoise;
    nr = length(samples);