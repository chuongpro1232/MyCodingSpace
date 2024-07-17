package week2;

import java.util.Scanner;

//if you know you know!
public class ex4 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("What is your sentence?");
        String sentence = scan.nextLine();
        String lsentence = sentence.toLowerCase();
        int secondline = sentence.length() - 1;

        for (int i = 0; i <= lsentence.length() / 2; i++) {
            if (lsentence.charAt(i) == ' ') {
                continue;
            }

            for (int y = secondline; y >= 0; y--) {
                if (lsentence.charAt(y) == ' ') {
                    continue;
                }
                if (lsentence.charAt(y) == lsentence.charAt(i)) {
                    secondline = y;
                    break;
                }
            }
            if (lsentence.charAt(i) != lsentence.charAt(secondline)) {
                System.out.print("The phrase is not palindromes");
                break;
            }
            if (i == lsentence.length() / 2) {
                System.out.print("The phrase is palindromes");
            }
        }
    }
}
