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
#include <string.h>
#define SIZE 5
#define SIZEB 10
#define SIZEC1 4
#define SIZEC2 5
#define SIZED 20
int sumd(int n[]) // Accept an array and return sum of all numbers divisible by 3
{
    int sum3 = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (n[i] % 3 == 0)
        {
            sum3 += n[i];
        }
    }
    return sum3;
    //this one will return the sum of its
}

void stri(char str[]) // Accept a string and print out all alphabetical characters in that string.

{
    printf("\n");
    for (int i = 0; i < SIZEB; i++)
    {
        if ((str[i] > 'A' && str[i] < 'Z') || (str[i] > 'a' && str[i] < 'z')) 
        {
            printf("%c", str[i]);
        }
    }
}


int compare(int a1[], int a2[]) // Accept two arrays namely arr1 and arr2 and return 1 if all elements of arr1 are smaller than all
// elements of arr2, return 0 otherwise.
{
    for (int i = 0; i < SIZEC1; i++)
    {
        for (int j = 0; j < SIZEC2; j++)
        {
            if (a1[i] > a2[j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void replaced(char str1[], char str2[]) /*Accept two arrays namely arr1 and arr2 and return 1 if all elements of arr1 are smaller than all
elements of arr2, return 0 otherwise.*/
{
    char temp[SIZED];
    int space;
    for (int i = 0; i < SIZED; i++)
    {
        if (str1[i] == ' ')
        {
            space = i;
            break;
        }
    }
    strncpy(temp, str1 + space, strlen(str1) - space);
    strcat(str2, temp);
    strcpy(str1, str2);
    printf("\n%s", str1);
}

int main()
{
    int array[SIZE] = {3, 8, 2, 12, 6};
    printf("The sum of all number divisable by three is: %d", sumd(array));
    char string[SIZEB] = "N1ngi235Ni";
    stri(string);
    int arr1[SIZEC1] = {2, 3, 4, 5}, arr2[SIZEC2] = {10, 9, 30, 21, 32};
    printf("\n%d", compare(arr1, arr2));
    char mainStr[SIZED] = {"76!Niiii 12 ni"}, subStr[SIZED] = {"Helloo31"};
    replaced(mainStr, subStr);
    return 0;
}