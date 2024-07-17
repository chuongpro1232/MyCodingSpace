#include <stdio.h>
int main()
{
    int row, col;
    printf("  X  |");
    for (int i = 1; i <= 10; i++)
    {
        printf("%4d", i);
        if (i == 10)
        {
            printf("\n");
            for (int x = 0; x <= 10; x++)
            {
                printf("----");
            }
        }
    }
    printf("\n");
    for (int col = 1; col <= 10; col++)
    {
        printf("%3d  |", col);
        for (row = col; row <= col * 10; row += col)
        {
            printf("%4d", row);
        }
        printf("\n");
    }
    return 0;
}
