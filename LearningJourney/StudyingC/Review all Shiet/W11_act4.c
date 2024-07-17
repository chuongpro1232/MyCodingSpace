#include <stdio.h>
#define SIZE 5

int main()
{
    int number[SIZE];
    int change = 0;
    printf("what are ur five numbers:? ");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &number[i]);
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (number[i] > number[j])
            {
                change = number[i];
                number[i] = number[j];
                number[j] = change;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", number[i]);
    }
}
