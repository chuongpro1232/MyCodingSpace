package week1;
import java.util.Arrays;
public class ex3 {
    public static void main(String[] args) {
        int[] number = new int[100];
        int count =0;
            for (int z = 100; z<=201; z++) {
                if(z%5==0||z%6==0){


                    if (count ==10){System.out.println();
                    count =0;}
                    System.out.print(z+" ");
                    count ++;

                }
            }
        }
}



