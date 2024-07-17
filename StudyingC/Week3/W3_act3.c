#include <stdio.h>

int main (){
    int ascii,i=0;
    ascii=33;           
         while(ascii<127){
            printf("%3c ",ascii);
            ascii++;
            i++;
            if(i>14){
                printf("\n");
                i=0;
            }
         }
    


return 0;
}