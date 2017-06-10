function [ a ] = absorption( f )
% Calculation of underwater communication absorption coefficient (in dB/km)
% f = frequency (in k Hertz)
f2 = f*f; % square of frequency
a=0.11*f2/(1+f2) + 44*f2/(4100+f2) + 2.75*0.0001*f2 + 0.003;
end

