package week1;
import java.util.Scanner;
public class ex5 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the number of lines: ");
        int number = scan.nextInt();
        for (int col = 1;col <=number;col++){
            for (int space=number;space>col;space--) {
                System.out.print("   ");
            }
            for (int row=col;row>0;row--){
                System.out.print("  "+row);
                if(row==1){
                    for (int row2=2;row2<=col;row2++){
                        System.out.print("  "+row2);
                    }
                }
            }
            System.out.println();
        }
    }
}
