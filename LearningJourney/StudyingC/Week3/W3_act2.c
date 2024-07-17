#include <stdio.h>

int main (){
    int number,count,sum;
    count =0;
    sum =0;
    do  {
        printf ("Enter a positive interger:");
        scanf ("%d",& number);
        if(number<0){   
            break;
        }
        else{
            sum+=number;
            count+=1;
        }
    }
    while(1);
    printf ("Sum is %d \n",sum);
    printf ("There are %d positive number",count); 
    


return 0;
}