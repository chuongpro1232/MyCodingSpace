#include <stdio.h>

int power(int a, int b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
    {
        result *= a;
    }
    return result;
}

int main()
{
    int base, exponent;
    printf("Your number and exponent is: ");
    scanf("%d %d", &base, &exponent);
    int result = power(base, exponent);
    printf("The number is: %d", result);
}