// From VOQUANGCHUONG With love <3
#include <stdio.h>

int main()
{
    char c;

    printf("Enter an alphanumberical character: ");
    c = getchar();

    if (c >= 48 && c <= 57)
    {
        printf("it's a number\n");
    }
    else if (c >= 65 && c <= 90)
    {
        printf("it's a Uppercase alphabetical character\n");
        c = c + 32;
        printf("> Converted character: %c\n", c);
    }
    else if (c >= 97 && c <= 122)
    {
        printf("it's a Lowercase alphabetical character\n");
        c = c - 32;
        printf("> Converted character: %c\n", c);
    }
    else
    {
        printf("It's not alphanumberical character\n");
    }
    system("pause");
}