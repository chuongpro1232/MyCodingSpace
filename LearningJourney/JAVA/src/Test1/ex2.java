/*
  RMIT University Vietnam
  Course: INTE2512 Object-Oriented Programming
  Semester: 2023A
  Assessment: Test 1
  Author: Tran Thanh Tu
  ID: S3957386
  Created  date: 15/04/2023
  Acknowledgement:https://www.geeksforgeeks.org/print-characters-frequencies-order-occurrence/
  https://www.geeksforgeeks.org/program-print-substrings-given-string/
  https://stackoverflow.com/questions/55129028/java8-create-hashmap-with-character-count-of-a-string
  https://stackoverflow.com/questions/43643297/reading-an-int-and-a-char-input-using-a-scanner

*/

package Test1;

import java.util.Scanner;
import java.util.HashMap;

public class ex2 {
    public static void main(String[] args) {
        String str;
        Scanner scan = new Scanner(System.in);
        boolean validInput = false;
        do {// use do while loop to ask until the user enters valid input
            System.out.print("Input: ");

            str = scan.nextLine();

            if (str.matches("^[a-zA-Z]+(\\s+[a-zA-Z]+)*$")) { // check wheter the input is valid
                validInput = true;
            } else {
                System.out.println("Invalid input! Please re-enter the input: ");
            }
        } while (!validInput);

        String[] chars = str.split("\\s+");// Split the string into an array

        HashMap<String, Integer> charCount = new HashMap<>(); // storing the count of each character

        for (String c : chars) {// loop through the array of char
            if (charCount.containsKey(c)) {
                charCount.put(c, charCount.get(c) + 1); // count how many time a char appear
            } else {
                charCount.put(c, 1);
            }
        }

        System.out.println("Output: ");
        for (String c : charCount.keySet()) {// Prints out all the characters that appear exactly two times.
            if (charCount.get(c) == 2) {
                System.out.print(c + " ");
            }
        }
    }

}
