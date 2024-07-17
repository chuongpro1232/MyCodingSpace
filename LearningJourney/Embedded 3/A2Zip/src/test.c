// #include <stdio.h>
// #include <conio.h>

// int main()
// {
//     int ch;

//     printf("Press the up or down arrow key (or 'q' to quit):\n");

//     while (1)
//     {
//         ch = getch(); // Get a character from the keyboard

//         if (ch == 0xE0)
//         {                 // Check for extended key
//             ch = getch(); // Read the extended key
//             if (ch == 72)
//             {
//                 printf("Up arrow key pressed\n");
//             }
//             else if (ch == 80)
//             {
//                 printf("Down arrow key pressed\n");
//             }
//         }
//         else if (ch == 'q' || ch == 'Q')
//         {
//             printf("Exiting...\n");
//             break; // Exit the loop if 'q' is pressed
//         }
//     }

//     return 0;
// }