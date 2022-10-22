function [t1,t2,t3] = IK_XYZ(x,y,z)

L1 = 1;
L2 = 3;
L3 = 3;

if (x >= 0) && (y >= 0)
    t1 = atan(y/x);
elseif (x <= 0) && (y <= 0)
    t1 = pi + atan(y/x);
elseif (x > 0) && (y < 0)
    t1 = 2 * pi - atan(y/x);
else
    t1 = pi - atan(y/x);
end

r = sqrt (( x ^ 2 + y ^ 2) + (z - L1) ^ 2);

t3 = acos((-(L2^2) - (L3^2) + r^2) / (2*L2*L3));

b = acos((r^2 + L2^2 - (L3^2)) / (2*L2*r));

t2 = atan((z - L1) / (sqrt(x^2 + y^2))) - b ;

% Suponga que quiere ir desde 0,0 hasta 1,1
% Sin tomar en cuenta la altura.
% El largo de la linea debe ser sqrt(2)
% Se muestra el Plot de la vista superior

f1 = figure;
%f2 = figure;

x = 0;
y = 0;

x1 = x + ((L2 + L3) * cos (t1));
y1 = y + ((L2 + L3) * sin (t1));

%figure(f2);
%title('Vista Superior X,Y')
% Para validar este plot usar (1,1) con largo sqrt(2)
% y se podra observar que el angulo es de 45 grados.
%plot([x x1],[y y1]);    
%hold off;


% Ahora tomamos un punto al cual queremos ir.
% Suponga el plano x,z
% tomamos desde 0,0 hasta 1,1
x = 0;
z = L1; % Altura z inicial

x2 = x + (L2 * cos (t2));
z2 = z + (L2 * sin (t2));

figure(f1);
title('Vista Lateral X,Z')
plot([x x2],[z z2]);
hold on;

x = x2;
z = z2;

x3 = x + (L3 * cos (t3));
z3 = z + (L3 * sin (t3));

plot([x x3],[z z3]);




