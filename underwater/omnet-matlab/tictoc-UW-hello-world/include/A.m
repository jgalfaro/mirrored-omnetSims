function [ L ] = A( a, k, d )
% Calculation of underwater attenuation (in linear form)
% a = absorption coefficient (in dB/km)
% k = geometry of propagation 1=cylindrical, 2=spherical, 1.5 practical
% d = distance (in km)
L = power(10.0,( k*10.0*log10(d) + d * a ) /10.0);
end
