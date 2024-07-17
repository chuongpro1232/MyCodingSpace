#include <stdio.h>

int main(void)
{
    int num;

    // Get valid number
    while (1)
    {
        printf("Enter a number (1 - 10): ");
        scanf("%d", &num);

        if (num < 1 || num > 10)
        {
            printf("Invalid Number\n");
        }
        else
        {
            break;
        }
    }

    // Print out pattern
    for (int row = 1; row <= num; row++)
    {
        // Print out 1st row (values 1 -> num)
        if (row == 1)
        {
            for (int val = 1; val <= num; val++)
            {
                printf("%2d  ", val);
            }
        }
        else
        { /* For other rows*/
            // Print out descending numbers (values row -> 1)
            for (int val = row; val >= 1; val--)
            {
                printf("%2d  ", val);
            }

            // Print blocks of white spaces (num - row - 1 blocks)
            for (int block = 1; block <= num - row - 1; block++)
            {
                printf("    ");
            }

            // Print last value (   num - row  - 1), except last row
            if (row < num)
            {
                printf("%2d  ", num - row + 1);
            }
        }

        printf("\n"); // end each row --> go to new line
    }

    return 0;
}