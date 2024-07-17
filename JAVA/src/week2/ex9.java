package week2;

import java.util.Scanner;

public class ex9 {
    public static void main() {
        Scanner scan = new Scanner(System.in);
        int[] numbers = new int[101];
        while (scan.hasNextInt()) {
            int number = scan.nextInt();
            if (number == 0)
                break;
            numbers[number] += 1;
        }

        for (int i = 1; i < 101; i++) {
            if (numbers[i] > 0) {
                System.out.print(i + "occurs" + numbers[i] + "time");

                if (numbers[i] > 1)
                    System.out.print("s");
                System.out.print("\n");
            }
        }
    }
}
