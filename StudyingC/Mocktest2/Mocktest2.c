#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int min(int array[], int size)
{
    int min = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

float avr(int array[], int size)
{
    float result = 0;
    for (int i = 0; i < size; i++)
    {
        result += array[i];
    }
    result = result / size;
    return result;
}

void halfprint(int array[], int size)
{
    int half = 0;
    half = size / 2;
    for (int i = 0; i < half; i++)
    {
        printf("%d\n", array[i]);
    }
}

int closest(int array[], int size, int number)
{

    int closest = 0;
    for (int i = 0; i < size; i++)
    {
        if (abs(array[closest] - number) > abs(array[i] - number))
        {
            closest = i;
        }
    }
    return closest;
}

int main()
{
    int array[SIZE] = {3, 2, 5, 8, 4};

    int minnum = min(array, SIZE);
    printf("%d\n", minnum);
    float averageresult = avr(array, SIZE);
    printf("%.2f\n", averageresult);

    halfprint(array, SIZE);

    int closestarray = closest(array, SIZE, 6);
    printf("closest number is: %d", array[closestarray]);
    return 0;
   