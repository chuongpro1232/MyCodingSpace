// Bai A
#if 0
#include <stdio.h>
#define SIZE 5

void print(int array[], int size)
{
    printf("The numbers in the array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int array[SIZE] = {12, 7, -3, 4, 1};

    print(array, SIZE);
}
#endif

// Bai B
#if 0
#include <stdio.h>
#define SIZE 5

void print(int array[], int size)
{
    printf("The numbers in the array is: ");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int array[SIZE] = {12, 7, -3, 4, 1};

    print(array, SIZE);
}
#endif

// Bai C
#if 1
#include <stdio.h>
#define SIZE 5

void print(int array[], int size)
{

    printf("The numbers in the array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
        // if (array[i] < array[i + 1])
        // {
        //     max = array[i + 1];
        // }
    }
    //     printf("the biggest number is: %d", max);
}






int compare(int array[], int size)
{
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    // printf("Maximum: %d", max);
    return max;
}

int main()
{
    int array[SIZE] = {12, 7, -3, 4, 1};

    print(array, SIZE);
    compare(array, SIZE);
    int max = compare(array, SIZE);
    // int max= max(compare);
    printf("Maximum: %d", max);
}
#endif