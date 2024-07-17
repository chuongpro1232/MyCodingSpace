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
#define SIZE 30

void replace(char string[], int size) // this function use to replace digits with * and #
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= '0' && string[i] <= '5') // this one will replace all digits bigger than 0 and lower than 5 to *
        {
            string[i] = '*';
        }
        else if (string[i] >= '6' && string[i] <= '9') // this one will replace all digits bigger and equal to 6 and lower and equal to 9 to #
        {
            string[i] = '#';
        }
    }
}

int main()
{
    char string[SIZE]; // declared string with the maximum size is SIZE
    printf("Enter a string: ");
    scanf("%[^\n]s", string);             // it will scan til the new line
    replace(string, SIZE);                // function go here
    printf("your result is: %s", string); // print out the result
    return 0;
}
