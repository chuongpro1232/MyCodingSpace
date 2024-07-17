#include <stdio.h>

int main()
{
    int number_request;

    // do
    // {
    // printf("Put your number here (1-10): ");
    // scanf("%d", &number_request);
    // if (number_request > 0 && number_request <= 10)
    // {
    //     break;
    // }
    // else
    // {
    // printf("Invalid Number\n");
    // }
    do
    {
        printf("Put your number here (1-10): ");
        scanf("%d", &number_request);
        if (number_request <= 0 || number_request > 10)
            printf("Invalid Number\n");

    } while (number_request <= 0 && number_request > 10);

    for (int row = 1; row <= number_request; row++)
    {
        for (int print = row; print > 0; print--)
        {
            printf("%3d", print);

            if (row == 1)
            { // vong lap in so tu 1
                for (int first_line = 2; first_line <= number_request; first_line++)
                {
                    printf("%3d", first_line);
                }
            }
        }
        for (int white_space = number_request - row; white_space > 1 && white_space < number_request - 1; white_space--)
        {
            printf("   ");
        }
        if (row < number_request && row > 1)
        {
            printf("%3d", number_request - row + 1);
        }

        printf("\n");
    }

    return 0;
}