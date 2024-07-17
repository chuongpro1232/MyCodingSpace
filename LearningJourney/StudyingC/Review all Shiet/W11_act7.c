/*Write a recursive function that takes an array of integers as parameters and returns the sum
of the elements in the array.*/

#include <stdio.h>
#define SIZE 5

int sum(int num[], int size)
{
    int static total = 0;
    if (size == 1)
    {
        return total += num[0];
    }
    size--;
    total += num[size];
    sum(num, size);
}

int main()
{
    int array[SIZE] = {4, 5, 3, 1, 9};
    printf("%d", sum(array, SIZE));
    return 0;
}