/*
  RMIT University Vietnam
  Course: EEET2601 Engineering Computing 1
  Semester: 2021C
  Lab Assessment: 3
  Author: Tran Thanh Tu
  ID: 3957386
  Compiler used: 8.1.0
  Created  date: 20/5/2022
  Acknowledgement: None
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 8

int main()
{
    //Create an array of 8 integers with values are generated random numbers from -100 to 100
    int array[SIZE];
    int smallest, negative = 0, positive = 0; //declaring

    srand(time(NULL)); //random
    printf("Array values: ");
    for (int i = 0; i < SIZE; i++) //loop for creating random number and also printing
    { 
        array[i] = rand() % 201 + (-100);
        printf(" %d", array[i]);
    }

    
    smallest = array[0];
    for (int i = 0; i < SIZE; i++) //finding the smallest number
    {
        if (smallest > array[i])
        {
            smallest = array[i];
        }
    }
    printf("\nSmallest odd value: %d", smallest);//print out the smallest number

    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] < 0)
        {
            negative++;
        }
        else
        {
            positive++;
        }
    } //this one count the number of positive and negative one
    printf("\nNumbers of positive and negative values: %d %d", positive, negative);
    return 0;
}