#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
    int n, temp;
    int num[SIZE];
    printf("your number is:");
    scanf("%d", &n);
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        num[i] = rand() % (n + 1);

        printf(" %d", num[i]);
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {

            if (num[j] < num[i])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    printf("\nThe number after sort is:");
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %d", num[i]);
    }
    return 0;
}