a = imread('coloredChips.png');
figure(1), imshow(a);

% Creat menu of color
disp('Color selection')
disp('r for red')


% Now we want input from user to tell us which color to change
x = input(' Please select the color you want to change: ','s');

copy = a;

dimension = size(a);
row_n = dimension (1);
col_n = dimension (2);

switch x
    case 'r'
        for row = 1:row_n
            for col = 1:col_n
                pixel_red = a(row,col,1);
                pixel_green = a(row,col,2);
                pixel_blue = a(row,col,3);
                
                if (pixel_red >= 200) && (pixel_green <= 50) && (pixel_green >= 5)  && (pixel_blue <= 80)
                    copy(row,col,1) = 0;
                    copy(row,col,2) = 0;
                    copy(row,col,3) = 0;
                end
            end
        end
        
    otherwise
        disp('Incorrect selection, please choose from the menu');
end


% display the modified image
figure(2),imshow(copy);