package week2;

import java.util.Scanner;
import java.util.HashSet;

public class ex8 {
    public static void main(String args[]) {
        HashSet<Integer> number = new HashSet<Integer>();
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter ten number:");
        for (int i = 0; i < 10; i++) {
            int numberinp = scan.nextInt();
            number.add(numberinp);
        }
        System.out.printf("The number of distinct number is %d\n", number.size());
        System.out.printf("The distinct numbers are ");
        for (int numberoup : number) {
            System.out.print(numberoup + " ");
        }
    }
}
