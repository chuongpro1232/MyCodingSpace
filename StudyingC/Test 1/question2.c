
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
#include <time.h>
#include <stdlib.h>

int main()
{
    const int SIZE = 8;
    int num[8], count, sum = 0;

    srand(time(NULL));

    // QUESTION A

    for (int i = 0; i < SIZE; i++)
    {
        num[i] = rand() % 151 + 50;
    }
    printf("Generated Array: \n");

    for (int i = 0; i < SIZE; i++)
    {
        printf("%2d  ", num[i]);
    }

    // QUESTION B

    printf("\n\nAll elements which are even numbers: \n");
    for (int i = 0; i < SIZE; i++)
    {
        if (num[i] % 2 == 0)
        {
            printf("%2d  ", num[i]);
            count++;
            sum += num[i];
        }
    }
    printf("\nThere are %d elements sastified the condition\n", count);
    printf("Their sum: %d", sum);

    return 0;
}