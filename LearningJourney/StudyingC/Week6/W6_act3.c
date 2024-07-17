#include <stdio.h>
#define SIZE 100

int main()
{
    int count = 0;
    char input[SIZE];
    char changing;
    char huh;
    printf("What is your string?: ");
    scanf("%[^\n]s", input);

    for (int i = 0; input[i] != '\0'; i++)
    {
        count++;
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] = input[i] - ('a' - 'A');
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] = input[i] + ('a' - 'A');
        }
        // printf("%d", count);
    }

    printf("the number of character in the string is: %d\n", count);
    for (int i = 0; input[i] != '\0'; i++)
    {
        printf("%c", input[i]);
    }

    printf("\nFind: ");
    scanf("%c", &huh);

    printf("\nFind: ");
    scanf("%c", &changing);

    return 0;
}