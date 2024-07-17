#include <stdio.h>

int prime(int num)
{
    int result = 0;
    int check = 0;
    for (int i = num - 1; i >= 2; i--)
    {

        result = num % i;
        if (result == 0)
        {
            check++;
            break;
        }
    }
    return check;
}

int main()
{
    int num;
    printf("Your number to check:");
    scanf("%d", &num);
    int check = prime(num);
    if (check == 0)
    {
        printf("Your number is prime number\n");
    }
    else
    {
        printf("your number is not prime number");
    }
    return 0;
}