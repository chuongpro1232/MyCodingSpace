#include <stdio.h>

int main()
{
    int num = 21;
    int *ip;
    ip = &num;

    printf("%d", ip);

    return 0;
}