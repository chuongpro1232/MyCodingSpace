#include <stdio.h>
#define SIZE 30

int main()
{
    char string[SIZE];
    int space = 0, longest_space = 0, temp = 0, start = 0;
    printf("Your string is:");
    scanf("%[^\n]s", string);

    for (int i = 0; i < SIZE; i++)
    {
        if (string[i] >= '0' && string[i] <= '9')
        {
            printf("%c ", string[i]);
        }
    }
#if 0
    // for (int i = 0; i < SIZE; i++)
    // {
    //     if (string[i] == ' ')
    //     {
    //         string[i] = '\n';
    //     }
    // }
    // printf("\n%s", string);
    // printf("\n");
#endif
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (string[i] == ' ' || string[i] == '\0')
        {
            temp = i - space;
            if (temp > longest_space)
            {
                longest_space = temp;
                start = i - longest_space;
            }
            space = i;
        }
    }

    for (int i = start; i < start + longest_space; i++)
    {
        printf("%c", string[i]);
    }
}