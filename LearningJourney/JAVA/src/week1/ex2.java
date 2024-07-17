package week1;

import java.util.Scanner;
public class ex2 {
    public static void main(String[] args) {
        Scanner scan = new Scanner (System.in);
        int number;
        while (true) {
            System.out.println("What is your number?:");
            number = scan.nextInt();
            if (number > 0){
                if (number %5==0 && number % 6 == 0){
                    System.out.printf("%d is divisible by both 5 and 6\n",number);
                }
                else if (number %5==0 || number % 6 == 0) {
                    System.out.printf("%d is divisible by 5 or 6, but not both\n",number);
                }
                else {
                    System.out.printf("%d is neither divisible by 5 nor 6\n",number);
                }

            }
            else {
                System.out.printf("Your number is not a positive number: %d",number);
                System.out.println("\nGood Bye!");
                break;
            }
        }

    }
}
