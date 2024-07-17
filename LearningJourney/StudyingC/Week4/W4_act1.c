#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int num[10];
    int a, small = 0;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int a = rand() % 51 + 50;
        // printf("%d ",a);
        num[i] = a;
    }
    for (int i = 10; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (num[i] > num[j])
            {
                small = num[j];
            }
        }

        printf("%d ", num[i]);
    }
    printf("\n");
    printf("%d", small);
    // for (int i=0; i<10; i++){

    //     if (num[i]>80){
    //         printf("%d ",num[i]);
    //     }
    // }

    // int a;
    // srand(time(NULL));
    // for (int i =0; i <11; i++){
    //     a =rand()%101;
    //     printf("%d",a);
    // }

    return 0;
}