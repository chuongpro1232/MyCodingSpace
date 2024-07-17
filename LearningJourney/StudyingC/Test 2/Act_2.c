/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2021C
  Lab Assessment: 2
  Author: Tran Thanh Tu
  ID: 3957386
  Compiler used: 8.1.0
  Created  date: 29/4/2022
  Acknowledgement: None
*/

#include <stdio.h>
#define SIZE 7
#define SIZE2 2

void larger(int array[], int size) // this function will find all the number which is larger than 5
{
    printf("All number which larger than 5 is:");
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 5) // if array bigger than 5 it will print out
        {
            printf(" %d", array[i]);
        }
    }
}

int sumnumber(int array[], int size) // this function will find out all odd number and calculate its sum
{
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0) // this function will help us know whether the number is even or odd
        // if modulo of array with 2 equal to 1, it will take that number and plus with sum
        {
            result += array[i];
        }
    }
    return result;
}

void small(int array[], int size) // this function will find out the smallest number
{
    int smallestnum = 1000;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            if (array[i] < smallestnum)
            {
                smallestnum = array[i];
            }
        }
    }
    printf("\nthe smallest even number is: %d", smallestnum);
}

int compare(int array1[], int array2[], int size1, int size2) // this function will compare two array
{
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size1; j++)
        {
            if (array1[j] > array2[i])
            {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    int array[SIZE] = {3, 5, 8, 8, 7, 9, 7};
    larger(array, SIZE);
    sumnumber(array, SIZE);
    small(array, SIZE);
    int array2[SIZE2] = {13, 23};
    printf("\n%d", compare(array, array2, SIZE, SIZE2));
    return 0;
}