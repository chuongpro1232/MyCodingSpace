/*Write your own version of the C library function int atoi(const char *str) which
converts a string of digits str to an integer value and returns it. If no valid conversion
could be performed, the function returns zero.*/

#include <stdio.h>
#include <string.h>

int atoi(const char *str)
{
    int digits;
    int count = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 1; j < strlen(str) - i; j++)
        {
            count *= 10;
        }
        digits += (*(str + i) - '0') * count;
        count = 1;
    }
    printf("the number is: %d", digits);
}

int main()
{
    const char *strdigits = "2331459";
    atoi(strdigits);
}