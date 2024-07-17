package JAVA.Java2;

import java.util.Scanner;
import java.util.Arrays;

public class test {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("What is your three numbers?: ");
        int[] number = new int[3];

        for (int i = 0; i < 3; i++) {
            number[i] = scan.nextInt();
        }
        Arrays.sort(number);
        for (int i = 0; i < 3; i++) {
            System.out.print(number[i] + " ");
        }
    }
}
