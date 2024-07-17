#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
    char dest[SIZE], source[SIZE];
    int space = 0, space2 = 0;
    int comma = 0;
    printf("Enter your info:");
    scanf("%[^\n]s", source);
    for (int i = 0; i < SIZE; i++)
    {
        if (source[i] == ' ')
        {
            space = i;
            break;
        }
    }
    strncpy(dest, source, space);

    for (int i = 0; i < SIZE; i++)
    {
        if (source[i] == ',')
        {
            comma = i;
        }
        for (int j = 0; j < comma; j++)
        {
            if (source[j] == ' ')
            {

                if (abs(space2 - comma) > abs(j - comma))
                {
                    space2 = j;
                }
            }
        }
    }
    strncpy(dest + space, source + space2, comma - space2);

    int year = (source[comma + 2] - '0') * 1000 + (source[comma + 3] - '0') * 100 + (source[comma + 4] - '0') * 10 + (source[comma + 5] - '0');
    // printf("%d", year);
    // int wordyear = 2022 - year;

    printf("Result: %s ,%d-years-old", dest, 2022 - year);
    return 0;
}
