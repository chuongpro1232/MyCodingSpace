package week2;

import java.util.Scanner;

public class ex2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the first city:");
        String firstcity = scan.nextLine();
        char char1 = firstcity.charAt(0);
        System.out.println("Enter the second city:");
        String secondcity = scan.nextLine();
        char char2 = secondcity.charAt(0);
        System.out.println("Enter the third city:");
        String thirdcity = scan.nextLine();
        char char3 = thirdcity.charAt(0);
        if (char1 < char2) {
            if (char2 < char3)
                System.out.printf("The three cities in Alphabetical order is %s %s %s", firstcity, secondcity,
                        thirdcity);
            else
                System.out.printf("The three cities in Alphabetical order is %s %s %s", firstcity, thirdcity,
                        secondcity);
        } else if (char2 < char1) {
            if (char1 < char3)
                System.out.printf("The three cities in Alphabetical order is %s %s %s", secondcity, firstcity,
                        thirdcity);
            else
                System.out.printf("The three cities in Alphabetical order is %s %s %s", secondcity, thirdcity,
                        firstcity);
        } else {
            if (char1 < char2)
                System.out.printf("The three cities in Alphabetical order is %s %s %s", thirdcity, firstcity,
                        secondcity);
            else
                System.out.printf("The three cities in Alphabetical order is %s %s %s", thirdcity, secondcity,
                        firstcity);
        }
    }
}
