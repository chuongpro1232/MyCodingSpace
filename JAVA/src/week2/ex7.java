package week2;

import java.util.Scanner;

public class ex7 {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        System.out.print("The scores is: ");
        int aboveavg = 0, belowavg = 0;
        int scores[] = new int[5];
        if (scan.hasNextInt()) {
            for (int i = 0; i < 30; i++) {
                scores[i] = scan.nextInt();
                if (scores[i] >= 5)
                    aboveavg++;
                else
                    belowavg++;
            }
        }

        System.out.printf(
                "The total of scores that are above average is: %d \nThe total of scores that are below average is: %d \n",
                aboveavg, belowavg);
    }

}
