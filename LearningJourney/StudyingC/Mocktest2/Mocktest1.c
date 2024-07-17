#include <stdio.h>
#include <string.h>
#define SIZE 30

// void typing(int string[], int size)
// {
//     printf("Your sentence is: ");
//     scanf("%[^\n]s", string);
//     // for (int i = 0; i < size; i++)
//     // {
//     printf("%s", string);
//     // }
// }

void replace(char string[], int size)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == 's')
        {
            string[i] = '$';
        }
        else if (string[i] == 'a')
        {
            string[i] = '@';
        }
        else if (string[i] == 'i')
        {
            string[i] = '1';
        }
        else if (string[i] == 'o')
        {
            string[i] = '0';
        }
    }
}

int main()
{
    char string[SIZE];
    printf("Enter your password: ");
    scanf("%[^\n]s", string);
    replace(string, SIZE);

    printf("result: %s", string);

    return 0;
}