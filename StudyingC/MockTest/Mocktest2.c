
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    srand(time(NULL));
    const int size = 20;
    int marks[20];
    for (int i = 0; i < 20; i++)
    {

        int num = rand() % 101;
        // printf("%d",num);
        marks[i] = num;
    }
    for (int i = 0; i < 20; i++)
    {
        if (marks[i] > 51 && marks[i < 101])
        {
            printf("%d ", marks[i]);
            n++;
        }
    }
    printf("\n");
    printf("There are %d number which bigger than 50", n);
}
