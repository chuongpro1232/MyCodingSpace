#if 0
#include <stdio.h>

int main()
{
#if 0
    int a;
    printf("nhap so ban muon: \n");
    scanf("%d",&a);
    printf("so ban vua nhap la: %d",a);
system("pause");
#endif

    int arr[] = {1, 2, 3, 4};
    printf("%d", arr);

    return 0;
}
#endif

// c.	Ask the user to enter a searching keyword, and text for replacement.
// Print out the string after replacement.

//     Enter a string: Good afternoon

// Find: oo
// Replace with: 00
// Result: G00d aftern00n

#include <stdio.h>
int abc(int i)
{
    return (i++);
}

int main()
{
    int i = abc(10);
    printf("%d", i);
    return 0;
}
// #include <string.h>
// #define SIZE 100

// int main()
// {
//     char str[SIZE], find[SIZE], replace[SIZE];

//     printf("Enter a string: ");
//     scanf("%[^\n]s", str);

//     printf("Find: ");
//     scanf(" %[^\n]s", find);

//     printf("Replace: ");
//     scanf(" %[^\n]s", replace);

//     for (int i = 0; str[i] != '\0'; i++)
//     { // index go from the beginning to the end
//         // find the match
//         if (strncmp(str + i, find, strlen(find)) == 0)
//         {
//             printf("Found at index i = %d \n", i);

//             // replace
//             strncpy(str + i, replace, strlen(find));
//         }
//     }

//     printf("The string after replacement: %s \n", str);

return 0;
}
