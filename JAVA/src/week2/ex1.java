package week2;

import java.util.Scanner;

public class ex1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int[] numbers = new int[123];
        System.out.println("Input:");
        if (scan.hasNextLine()) {
            String line = scan.nextLine();
            Scanner input = new Scanner(line);

            while (input.hasNextInt()) {
                int number = input.nextInt();
                numbers[number] += 1;
            }
        }
        for (int i = 97; i <= 122; i++) {
            if (numbers[i] >= 2) {
                System.out.printf("%c ", numbers[i]);
            }
        }
    }
}
