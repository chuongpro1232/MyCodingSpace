
/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2022A
  Lab Assessment: 1
  Author: Tran Thanh Tu
  ID: 3957386
  Compiler used: Compiler version 8.1.0
  Created  date: 25/03/2022
  Acknowledgement: None
*/

#include <stdio.h>

int main()
{
    int number, maxrow;

    // QUESTION A

    do
    {
        printf("Enter a number (1-10): ");
        scanf("%d", &number);
        if (number <= 0 || number > 10)
        {
            printf("Invalid Number\n");
        }
        else
        {
            break;
        }
    } while (1);
    if (number % 2 == 0)
    {
        for (int i = 1; i <= number; i++)
        {
            printf("1  ");
            maxrow = number - i;
            for (int j = 2; j > 1 && j <= maxrow + 1; j++)
            {
                printf("%2d  ", j);
            }
            printf("\n");
        }
    }
    else
    {
        maxrow = number;
        for (int i = 1; i < number; i++)
        {
            for (int j = number; j >= 1; j--)
            {

                // printf("%d",j);
                if (j == maxrow && j != 1)
                {
                    if (i == 1)
                    {
                        for (int a = number; a > 0; a--)
                        {
                            printf("%2d ", a);
                        }
                    }
                    printf("%2d ", maxrow);
                }
                else if (j == 1)
                {
                    printf("%3d ", j);
                }
                else if (j != maxrow)
                {
                    printf("    ");
                }
            }
            printf("\n");
            maxrow--;
        }
    }

    return 0;
}