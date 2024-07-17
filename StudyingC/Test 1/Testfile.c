#include <stdio.h>

int main (){
    int number,maxrow;
    printf("Enter a number (1-10): ");
    scanf("%d",&number);


     maxrow=number;
        // for (int i=1; i<number; i++){
        //     // printf("check");
        //     for (int j=number; j>=1; j--){
        //         if(j==number){
        //             for (int z=number; z>=1; z--){
        //                 printf("%2d ",z);
        //             }
        //         }
        //             else{
        //                 for (int z=0;z<=number; z++){
        //                     printf("  1 ");
        //                 }
        //             }
        //         }
        //         // printf("%d",j);
        //         // if(j==1){
        //         //     printf("  1 ");
        //         // }
        //         if(j==maxrow){
        //             printf("%2d ",maxrow);
        //         }
        //         else if (j!=maxrow){
        //             printf("    ");
        //         }
        //     }
        //     printf("\n");
        //     maxrow--;
        // }



        // for (int i=1; i<number; i++){
        //     for (int j=number; j>=1; j--){
        //         if(j==number){
        //             for (int z=number; z>=1; z--){
        //                 printf("%2d ",z);
        //             }
        //         }
        //          else{
        //                 for (int z=0;z<=number; z++){
        //                     printf("  1 ");
        //                 }
        //                 if(j==maxrow){
        //             printf("%2d ",maxrow);
        //         }
        //         else if (j!=maxrow){
        //             printf("    ");
        //         }
        //     }
        //     printf("\n");
        //     maxrow--;
        
        // }
        // }
        


        maxrow=number;
        for (int i=1; i<number; i++){
            for (int j=number; j>=1&&j<=number; j--){
                
                
                // printf("%d",j);
                if(j==maxrow&&j!=1){
                    if (i==1){
                        for (int a=number;a>0;a--){
                            printf("%2d ",a);
                        }
                    }
                    printf("%2d ",maxrow);
                }





                else if(j==1){
                    printf("%3d ",j);
                }
                else if (j!=maxrow){
                    printf("    ");
                }
                

                // if (i==1){
                //     for (int z=number-1;z>1;z--){
                //         printf("%2d ",z);
                //     }
                // }
                //     else{
                //         continue;
                //     }

            }
            printf("\n");
            maxrow--;
        }
        







    // return 0;
}