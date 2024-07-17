#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int main (){
//    int swap;
//    #define s 5
//    int marks[s] = {3,5,2,8};

//    for (int i=0;i<4;i++){
//       for (int j=i+1;j<4;j++){
//          if (marks[j] > marks[i]){
//             swap = marks[i] ;
//             marks[i] = marks[j];
//             marks[j] = swap;
//          }
//       }
//    }
//    for (int i=0;i<4;i++){
//       printf("%d",marks[i]);
//    }

//    // srand(time(NULL));
//    // int num = rand() %101;
//    // printf("%d",num);
// return 0;

// }

// #include <stdio.h>

// int main()
// {
//     printf("Enter 5 values: ")

//         int arr[5];
//     for (int i = 0; i < 5; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     printf("The array of 5 values: ");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%2d", arr[i]);
//     }

//     return 0;
// }

void func(int num, char str[])
{
    int lastdig = n % 10;
    str[(int)log10(num)] = lastdig + '0';
    if (num > 10)
    {
        func(num % 10, str);
    }
}

int main()
{
    int number = 2345;
    char str[5];
    func(number, str[5]);
    // int *i;
    // *i = 100;
    // printf("%d", *i);
    // return 0;
}
