#include <stdio.h>

void printStars(int stars)
{
    for (int i = 0; i < stars; i++)
    {
        printf("*");
    }
}

int main()
{
    int size;
    do
    {
        printf("Enter an odd number: ");
        scanf("%d", &size);
        if (size % 2 == 0 || size <= 0 || size > 15)
        {
            printf("invalid number!\n");
        }
    } while (size % 2 == 0 || size <= 0 || size > 15);

    int stars = 1;

    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < size / 2; i++)
        {
            printf(" ");
        }

        printStars(stars);
        printf("\n");

        //     if (i < size / 2)
        //     {
        //         spaces--;
        //         stars += 2;
        //     }
        //     else
        //     {
        //         spaces++;
        //         stars -= 2;
        //     }
    }

    return 0;
}