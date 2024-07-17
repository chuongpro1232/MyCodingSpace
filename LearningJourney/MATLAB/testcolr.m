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
                
                if (pixel_red >= 200) && (pixel_green <= 60) && (pixel_green >=3)  &&(pixel_blue<=100) && (pixel_blue >= 13) 
                    copy(row,col,1) = 0;
                    copy(row,col,2) = 0;
                    copy(row,col,3) = 0;
                end
            end
        end

     case 'b'
        for row = 1:row_n
            for col = 1:col_n
                pixel_red = a(row,col,1);
                pixel_green = a(row,col,2);
                pixel_blue = a(row,col,3);
                
                if (pixel_red <10) && (pixel_green <= 100)  &&(pixel_blue>100) 
                    copy(row,col,1) = 0;
                    copy(row,col,2) = 0;
                    copy(row,col,3) = 0;
                end
            end
        end
         case 'g'
        for row = 1:row_n
            for col = 1:col_n
                pixel_red = a(row,col,1);
                pixel_green = a(row,col,2);
                pixel_blue = a(row,col,3);
                
                if (pixel_red<50) &&(pixel_green >100)  &&(pixel_blue<=130) 
                    copy(row,col,1) = 0;
                    copy(row,col,2) = 0;
                    copy(row,col,3) = 0;
                end
            end
        end

         case 'y'
        for row = 1:row_n
            for col = 1:col_n
                pixel_red = a(row,col,1);
                pixel_green = a(row,col,2);
                pixel_blue = a(row,col,3);
                
                if (pixel_red >= 200) && (pixel_green >=200) &&(pixel_blue<=145)
                    copy(row,col,1) = 0;
                    copy(row,col,2) = 0;
                    copy(row,col,3) = 0;
                end
            end
        end
         case 'o'
        for row = 1:row_n
            for col = 1:col_n
                pixel_red = a(row,col,1);
                pixel_green = a(row,col,2);
                pixel_blue = a(row,col,3);
                
                if (pixel_red >= 220) && (pixel_green >= 30)&&(pixel_green>60)&&(pixel_green<=200) &&(pixel_blue<=100)
                    copy(row,col,1) = 0;
                    copy(row,col,2) = 0;
                    copy(row,col,3) = 0;
                end
            end
        end

            case 'c'
        for row = 1:row_n
            for col = 1:col_n
                pixel_red = a(row,col,1);
                pixel_green = a(row,col,2);
                pixel_blue = a(row,col,3);
                
                if (pixel_red <= 70) && (pixel_green <= 220)&&(pixel_green>=140)  &&(pixel_blue>=150)&&(pixel_blue<=230) 
                    copy(row,col,1) = 0;
                    copy(row,col,2) = 0;
                    copy(row,col,3) = 0;
                end
            end
        end

            case 'm'
        for row = 1:row_n
            for col = 1:col_n
                pixel_red = a(row,col,1);
                pixel_green = a(row,col,2);
                pixel_blue = a(row,col,3);
                
                if (pixel_red >95)&&(pixel_red<=230) && (pixel_green<=90)&& (pixel_green>=50)  &&(pixel_blue>=155) &&(pixel_blue<=240)
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