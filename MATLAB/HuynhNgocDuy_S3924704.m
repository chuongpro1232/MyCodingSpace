%%Temperature
%Converting Celsius into Fahrenheit
disp('This program convert Celsius into Fahrenheit');
ToC = input('Enter a temperature in Celsius: '); %prompts user to enter a value
ToF = ToC * 9/5 + 32; %equation of conversion
fprintf('Fahrenheit: %.2f°F \n', ToF); %print the result in command window
%Converting Fahrenheit into Celsius
disp('This program convert Fahrenheit into Celsius');
ToF = input('Enter a temperature in Fahrenheit: '); %prompts user to enter a value
ToC = (ToF - 32) * 5/9; %equation of conversion
fprintf('Celsius: %.2f°C \n', ToC); %print the result in command window

%%Length & Distance
%Converting Centimetres into Inches
disp('This program convert Centimetres into Inches');
Lcm = input('Enter length in centimetres: '); %prompts user to enter a value
Linch = Lcm / 2.54; %equation of conversion
fprintf('Inches: %.2finch \n', Linch) %print the result in command window
%Converting Inches into Centimetres
disp('This program convert Inches into Centimetres');
Linch = input('Enter length in Inches: '); %prompts user to enter a value
Lcm = Linch * 2.54; %equation of conversion
fprintf('Centimetres: %.2f \n', Lcm); %print the result in command window
%Converting Metres into Feet
disp('This program convert Metres into Feet');
Lm = input('Enter length in Metres: '); %prompts user to enter a value
Lft = Lm / 0.3048; %equation of conversion
fprintf('Feet: %.2f \n', Lft); %print the result in command window
%Converting Feet into Metres
disp('This program convert Feet into Metres');
Lft = input('Enter length in Feet: '); %prompts user to enter a value
Lm = Lft * 0.3048; %equation of conversion
fprintf('Metres: %.2f \n', Lm); %print the result in command window
%Converting Kilometres into Miles
disp('This program convert Kilometres into Miles');
Dkm = input('Enter length in Kilometres: ');
Dmi = Dkm / 1.609344; %equation of conversion
fprintf('Miles: %.2f /n', Dmi); %print the result in command window
%Converting Miles into Kilometres
disp('This program convert Miles into Kilometres');
Dmi = input('Enter length in Miles: '); %prompts user to enter a value
Dkm = Dmi * 1.609344; %equation of conversion
fprintf('Kilometres: %.2f /n', Dkm); %print the result in command window

%%Mass
%Converting Grams into Ounces
disp('This program convert Grams into Ounces');
mgr = input('Enter mass in Ounces: '); %prompts user to enter a value
moz = mgr / 28.3495; %equation of conversion
fprintf('Ounces: %.2f \n', moz); %print the result in command window
%Converting Ounces into Grams
disp('This program convert Ounces into Grams');
moz = input('Enter mass in Ounces: '); %promtps user to enter a value
mgr = moz * 28.3495; %equation of conversion
fprintf('Gramms: %.2f \n', mgr); %print the result in command window
%Converting Kilograms into Pounds
disp('This program convert Kilograms into Pounds');
mkg = input('Enter mass in Kilograms: '); %prompts user to enter a value
mlb = mkg / 0.4536; %equation of conversion
fprintf('Pounds: %.2f \n', mlb); %print the result in command window
%Converting Pounds into Kilograms
disp('This program convert Pounds into Kilograms');
mlb = input('Enter mass in Pounds: '); %prompts user to enter a value
mkg = mlb * 0.4536; %equation of conversion
fprintf('Kilograms: %.2f \n', mkg); %print the result in command window
%Converting Tonnes into Tons
disp('This program convert Tonnes into Tons');
mtonne = input('Enter mass in Tonnes: '); %prompts user to enter a value
mton = mtonne / 1.016; %equation of conversion
fprintf('Tons: %.2f \n', mton); %print the result in command window
%Converting Tons into Tonnes
disp('This program convert Tons into Tonnes');
mton = input('Enter mass in Tons: '); %prompts user to enter a value
mtonne = mton * 1.016; %equation of conversion
fprintf('Tonnes: %.2f \n',mtonne); %print the result in command window 