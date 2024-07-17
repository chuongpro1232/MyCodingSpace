%S3957386
%%Temperature
%Celcius to Fahrenheit
fprintf('Welcome to The converting application\n');
ent=input('Enter to continue:.....\n\n');
fprintf ('');
fprintf('Celcius to Fahrenheit converting\n');
DeC= input('Enter Temperature in Celcius(°C): ');%ask user to enter a value
DeF= (DeC* 9/5) + 32; %equation of conversion
fprintf('Fahrenheit: %.2f°F\n',DeF);%print the result in command window


%Fahrenheit to Celcius
fprintf('Fahrenheit to Celcius converting\n')
DeF= input('Enter Temperature in Fahrenheit(°F): ');%ask user to enter a value
DeC= (DeF - 32) * 5/9; %equation of conversion
fprintf('Celcius: %.2f°C\n',DeC);%print the result in command window 


%%Length & Distance
%Centimeter to Inch
fprintf('Centimeter to Inch converting\n');
Cen=input ('Enter Length in Centimeter(cm): ');%ask user to enter a value
Inc= Cen/2.54; %equation of conversion
fprintf('Inch: %.2f"\n',Inc);%print the result in command window 

%Inch to Centimeter
fprintf('Inch to Centimeter converting\n');
Inc=input('Enter Length in Inch("): ');%ask user to enter a value
Cen=Inc * 2.54; %equation of conversion
fprintf('Centimeter: %.2fcm\n',Cen);%print the result in command window

%meter to feet
fprintf('Meter to Feet converting\n');
Met=input('Enter Length in Meter(m): ');%ask user to enter a value
Ft=Met / 0.3048; %equation of conversion
fprintf('Feet: %.2fft\n',Ft);%print the result in command window

%feet to meter
fprintf('Feet to Meter converting\n');
Ft=input('Enter Length in Feet(ft): ');%ask user to enter a value
Met=Ft * 0.3048; %equation of conversion
fprintf('Feet: %.2fm\n',Met);%print the result in command window

%kilometer to miles
fprintf('Kilometer to Miles converting\n');
Kmet=input('Enter Length in Kilometer(km): ');%ask user to enter a value
Mil=Kmet/ 1.609344; %equation of conversion
fprintf('Miles: %.2fmiles\n',Mil);%print the result in command window

%miles to kilometer
fprintf('Miles to Kilometer converting\n');
Mil=input('Enter Length in Miles(miles): ');%ask user to enter a value
Kmet=Mil* 1.609344; %equation of conversion
fprintf('Kilometer: %.2fkm\n',Kmet);%print the result in command window

%%Mass
%grams to ounces
fprintf('Gram to Ounces converting\n');
gr=input('Enter Mass in Grams(g): ');%ask user to enter a value
oun=gr/ 28.3495; %equation of conversion
fprintf('Ounces: %.2foz\n',oun);

%ounces to grams
fprintf('Ounces to gram converting\n');
oun=input('Enter Mass in Ounces(oz): ');%ask user to enter a value
gr=oun * 28.3495; %equation of conversion
fprintf('Grams: %.2fgr\n',gr);%print the result in command window

%kilograms to pounds
fprintf('Kilograms to Pounds converting\n');
kil=input('Enter Mass in Kilograms(kg): ');%ask user to enter a value
pou= kil / 0.4536; %equation of conversion
fprintf('Pounds: %.2flb\n',pou);%print the result in command window 

%pounds to kilograms
fprintf('Pounds to Kilograms converting\n');
pou=input('Enter Mass in Pounds(lb): ');%ask user to enter a value
kil= pou * 0.4536; %equation of conversion
fprintf('Kilograms: %.2fkg\n',kil);%print the result in command window 

%Tonnes to Tons
fprintf('Tonnes to Tons converting\n');
tone = input('Enter mass in Tonnes: '); %ask user to enter a value
ton = tone / 1.016; %equation of conversion
fprintf('Ton: %.2f\n', ton); %print the result in command window

%Tons into Tonnes
fprintf('Tons to Tonnes converting\n');
ton = input('Enter mass in Tons: '); %ask user to enter a value
tone = ton * 1.016; %equation of conversion
fprintf('Tonnes: %.2ft \n',tone); %print the result in command window 

fprintf('---See You Again---\n');