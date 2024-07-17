package week2;

import java.util.Scanner;

public class ex6()
{

    public static void main (String args[]){
        System.out.print("Enter scores: ");
    Scanner readLine = new Scanner(System.in);
    if (readLine.hasNextLine()) {
    String line = readLine.nextLine();
    Scanner input = new Scanner(line);
    ArrayList<Integer> numbers = new ArrayList<>();
    double average;
    double sum = 0;
    int length = 0;
    int numOfAbove = 0;
    int numOfBelow = 0;
    while (input.hasNextInt()) {
    int number = input.nextInt();
    numbers.add(number);
    sum += number;
    ++length;
}
average = sum / length;
for (int number : numbers) {
if (number >= average)
++numOfAbove;
else
++numOfBelow;
}
System.out.println("\nAverage: " + average);
System.out.println("Above: " + numOfAbove);
System.out.println("Below: " + numOfBelow);
}
    }

}
