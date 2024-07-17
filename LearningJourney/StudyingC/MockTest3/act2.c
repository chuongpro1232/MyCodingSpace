#include <stdio.h>
#define SIZE 9

int counting(char str[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {

        if ((str[i] > 'a' && str[i] < 'z') || (str[i] > 'A' && str[i] < 'Z'))
        {
            count++;
        }
    }
    return count;
    
}



int main()
{
    char string[SIZE] = "12hello34";
    printf("The total of char is: %d", counting(string, SIZE));
    return 0;
}