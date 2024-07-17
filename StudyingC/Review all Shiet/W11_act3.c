/*Ask the user to input a valid number from 1 to 10 inclusively. If the input is out of that
range, prints out an error message and ask again until it is valid.
Then, print out the multiplication table like below*/

#include <stdio.h>

int main()
{
    // int number = 0;

    // for (int i = 0; i >= 0; i++)
    // {
    //     printf("what is your number(from 1-10)?");
    //     scanf("%d", &number);
    //     if (number <= 10 && number > 0)
    //     {
    //         break;
    //     }

    //     printf("The number is Invalid\n");
    // }
    // printf("  X |");
    // for (int i = 1; i <= number; i++)
    // {
    //     printf("%4d", i);
    //     if (i == number)
    //     {
    //         printf("\n ");
    //         for (int j = 0; j <= number; j++)
    //         {
    //             printf("----");
    //         }
    //     }
    // }
    // printf("\n");
    // for (int i = 1; i <= number; i++)
    // {
    //     printf("  %d |", i);
    //     for (int j = 1; j <= number; j++)
    //     {
    //         printf("%4d", i * j);
    //     }
    //     printf("\n");
    // }

    char string[100];
    printf("what is your sentence?");
    scanf(string[100]);
    for (int i = 0; i < 100; i++)
    {
        string[i] = (isupper(string[i])) ? tolower(string[i]) : toupper(string[i]);
    }

    printf("%c", string);
    return 0;
}