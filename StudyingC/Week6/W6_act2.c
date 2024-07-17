#include <stdio.h>
#define SIZE 5
int main()
{
    int swap, numsw;
    int arr[SIZE] = {12, 7, -3, 4, 1};
    int sum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        sum += arr[i];
    }
    printf("sum = %d", sum);

    for (int i = 0; i < SIZE / 2; i++)
    {
        numsw = SIZE / 2 - i;
        int z = 0;
        z = numsw + SIZE / 2;
        swap = arr[i];
        arr[i] = arr[z];
        arr[z] = swap;
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("\n%d", arr[i]);
    }
}