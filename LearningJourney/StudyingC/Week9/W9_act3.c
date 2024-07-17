#include <stdio.h>

void printdigit(int num)
{
    // base case
    if (num < 10)
    {
        printf("%d ", num);
        return;
    }

    printdigit(num / 10);

    // printf("%d ", num % 10);
}

int main()
{
    int number;
    printf("The number is: ");
    scanf("%d", &number);
    printdigit(number);
}