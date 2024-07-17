#include <stdio.h>

int main()
{
    char ch = 'A';
    int *ptr;
    *ptr = 'B';
    ch = *ptr;      
    printf("%c", ch);

    return 0;
}