/*
    RMIT University Vietnam
    Course: EEET2601 Engineering Computing 1
    Semester:  2022-3
    Lab Assessment: 1
    Author:  Tran Thanh Phong
    ID: 3979190
    Compiler used: gcc Question3.c
    Created  date:  18/11/2022
    Acknowledgement: None
*/
#include <stdio.h>

int main()
{
    int i, j, row, k;

    // Get valid number
    printf("Enter a number (1 - 10): ");
    scanf("%d", &row);
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        for (j = i; j < row; j++)
        {
            printf(" ");
        }
        for (k = 1; k <= row; k++)
        {
            printf("%2d", k);
        }
        printf("\n");
    }

    return 0;
}
