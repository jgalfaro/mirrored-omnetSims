% PSK Modulation, channel simulation and demodulation example
% Version: May 6, 2014

%%% Initialization
%
% sampling rate (in samples per second)
fs = 100000; 
% frequency of carrier (in Hertz)
fc = 20000; 
% symbol rate (in baud)
sps = 1000; 
% distance
d = 16; % km
% transmission power in linear form (in u Pa)
P = power(10,140/10);

%%% Modulation
%
sentPacket = ['all ' 'people ' 'seem ' 'to ' 'need ' 'data ' 'processing.'];
% OR
%byteStream = char(floor(94*rand(1, 1000)) + 32);
[s, nr]  = modulatePSK(sentPacket, fs, fc, sps);
% figure; plot(1:length(s),s); title('Input to simulated channel');

%%% Channel simulation
%
[r nr] = simulateChannel(s, fs, sps, d, P);
% figure; plot(1:length(r),r); title('Output from simulated channel');

%%% Demodulation
%
receivedPacket = demodulatePSK(r, length(sentPacket), fs, fc, sps);
char(receivedPacket)

exit
