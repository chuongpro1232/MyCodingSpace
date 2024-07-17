#include <stdio.h>
#define SIZE 20

int main()
{
    char input[SIZE];
    int count = 0, uppercase = 0, lowercase = 0, totallet = 0, digits = 0, punctuation = 0;
    char convert;

    printf("type your string here: ");
    scanf("%[^\n]s", input);

    for (int i = 0; input[i] != '\0'; i++)
    {
        count++;
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            uppercase++;
            input[i] += 'a' - 'A';
        }
        else if (input[i] >= 'a' && input[i] <= 'z')
        {
            lowercase++;
            input[i] -= 'a' - 'A';
        }
        else if (input[i] >= '0' && input[i] <= '9')
        {
            digits++;
        }
        else
        {
            punctuation++;
        }
    }
    printf("the length of the string is %d \n", count);
    totallet = uppercase + lowercase;
    printf("The number of Uppercase: %d \nThe number of lowercase: %d \n", uppercase, lowercase);
    printf("The number of total letter: %d \n", totallet);
    printf("The number of digits: %d \nThe number of punctuation: %d", digits, punctuation);

    // printf("\nConvert character: ");
    // for (int i=0; input[i]!='\0'; i++){

    //     printf("%c", input[i]);
    // }

    printf("\nSwap: ");
    for (int i = count; i >= 0; i--)
    {
        printf("%c", input[i]);
    }

    return 0;
}