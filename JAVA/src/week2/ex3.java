package week2;

import java.util.Scanner;

public class ex3 {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("What is your sentence?");
        String string = scan.nextLine();
        String reversedString = "";
        for (int i = string.length() - 1; i >= 0; i--)
            reversedString += string.charAt(i);
        System.out.println(reversedString);
    }
}
