package week2;

import java.util.Scanner;

public class ex5 {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter List: ");
        int MAX = scan.nextInt();
        int[] number = new int[MAX];
        for (int i = 0; i < MAX; i++) {
            number[i] = scan.nextInt();
        }
        for (int i = 1; i < MAX; i++) {
            if (number[i - 1] > number[i]) {
                System.out.println("The list is not sorted");
                break;
            }
            if (i == MAX - 1) {
                System.out.println("The list is sorted");
            }
        }
    }
}
