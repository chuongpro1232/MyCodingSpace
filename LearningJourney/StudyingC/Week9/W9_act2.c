#include <stdio.h>

int leapyear(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        return 0;
    }
    return 1;
}

int main()
{
    int checkyear;
    printf("What is the year:");
    scanf("%d", &checkyear);
    int check = leapyear(checkyear);

    (check == 0) ? printf("the year is leapyear") : printf("the year is not leapyear");

    // if (check == 0)
    // {
    //     printf("the year is leapyear");
    // }
    // else
    // {
    //     printf("the year is not leapyear");
    // }
}