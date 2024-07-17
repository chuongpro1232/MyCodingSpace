/*Create an array of 10 integers with values are generated random numbers from 0 to 200 inclusively and print out
all values. Print out largest value of the first half, and smallest value of the second haft
Hint: first half is the first 5 elements (indexes 0-4). Second half is the last 5 elements (indexes 5-9).
Sample Run
Array values: 91 40 88 32 125 189 198 51 155 107
Max of the first half: 125
Min of the second half: 51*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10

int main()
{
    // Create an array of 10 integers with values are generated random numbers from -100 to 100
    int array[SIZE];
    int largest = 0;
    int smallest = 0; // declaring

    srand(time(NULL)); // random
    printf("Array values: ");
    for (int i = 0; i < SIZE; i++) // loop for creating random number and also printing
    {
        array[i] = rand() % 201 + (0);
        printf(" %d", array[i]);
    }

    largest = array[0];
    for (int i = 0; i < SIZE / 2; i++) // finding the smallest number of first half
    {
        if (largest < array[i])
        {
            largest = array[i];
        }
    }
    printf("\nlargest Value of first half is %d", largest); // print out the smallest number

    smallest = array[0];
    for (int i = SIZE / 2; i < SIZE; i++) // finding the smallest number of first half
    {
        if (smallest > array[i])
        {
            smallest = array[i];
        }
    }
    printf("\nsmallest value of second half is %d", smallest); // print out the smallest number
    return 0;
}