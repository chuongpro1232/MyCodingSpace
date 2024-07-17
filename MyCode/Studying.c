#if 0
#include <stdio.h>

int main()
{
    int a;
    //     int a;
    //     printf("nhap so ban muon: \n");
    //     scanf("%d",a);
    //     printf("so ban vua nhap la: %d",a);
    // getchar();

    do
    {
        printf("Input");
        scanf("%d", &a);

    } while (a >= 0 && a <= 100);

    // do{
    //     printf("Input");
    //     scanf("%d",&a);
    //     if (a>=0&&a<=100){
    //         break;
    //     }
    // }
    // while (1);

    if (a >= 50 && a < 60)
    {
        printf("PA");
    }
    else if (a >= 60 && a < 70)
    {
        printf("CR");
    }
    else if (a >= 70 && a < 80)
    {
        printf("DI");
    }
    else if (a >= 80)
    {
        printf("HD");
    }
    else if (a < 50 && a >= 0)
    {
        printf("NN");
    }
    return 0;
}

#endif

#include <stdio.h>
#include <
#define SIZE 15

int main()
{
    char day[SIZE];
    printf("what is your (dd/mm/yyyy)?");
    scanf("%[^\n]s", day);
    if (day=="08/12/2003"){
        FILE *New_File 
    }
}