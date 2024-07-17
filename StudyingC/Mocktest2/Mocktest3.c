#include <stdio.h>
#include <string.h>
#define SIZE 50

// void(char *string)
// {
// }

int main()
{
    char source[SIZE], edited[SIZE];
    printf("Enter a date in dd/mm/yyyy: ");
    scanf("%[^\n]s", source);
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};




    int month_value = (source[3] - '0') * 10 + (source[4] - '0');


    
    // for (int i = 0; source[i] != '\0'; i++)
    // {
    //     if (source[i] == '/')
    //     {
    //         source[i] = ' ';
    //     }
    // }

    // // printf("%d", month_value);

    // // printf("%s", *(months + month_value - 1));
    // strncpy(source[3], *(months + month_value - 1), (strlen(*(months + month_value - 1)) + 1));
    // printf("%s", source);

    strncpy(edited, source, 3);
    edited[2] = ' ';

    strcpy(edited + 3, *(months + month_value - 1));
    edited[strlen(*(months + month_value - 1)) + 3] = ' ';

    strncpy(edited + 3 + strlen(*(months + month_value - 1)) + 1, source + 6, 4);
    edited[3 + strlen(*(months + month_value - 1)) + 5] = '\0';
    printf("The edited is: %s", edited);
}