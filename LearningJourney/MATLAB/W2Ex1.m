d = 183;
g = 9.8;
xd = 45;
xr = (xd*pi)/180;

a = sin(2*xr);

v0=sqrt((d*g)/a);
fprintf ('the initial velocity is %.2f KM/H',v0*3.6);
%ohsheshbro