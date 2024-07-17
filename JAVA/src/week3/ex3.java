package week3;

import java.util.Scanner;
import java.lang.Math;

public class ex3 {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        System.out.print("What is the three value of a, b and c:");
        double a = scan.nextDouble();
        double b = scan.nextDouble();
        double c = scan.nextDouble();
        QuadraticEquation equation = new QuadraticEquation(a, b, c);
        double discriminant = equation.getDiscriminent();
        if (discriminant > 0) {
            System.out.println("The roots are" + equation.getRoot1() + "and" + equation.getRoot2());

        } else if (discriminant == 0) {
            System.out.println("The root are" + equation.getRoot1());
        } else {
            System.out.println("The equation has no roots");
        }
    }

}

class QuadraticEquation {
    private double a;
    private double b;
    private double c;

    public QuadraticEquation(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public double getA() {
        return a;
    }

    public double getB() {
        return b;
    }

    public double getC() {
        return c;
    }

    public double getDiscriminent() {
        return ((b * b) - 4 * a * c);
    }

    public double getRoot1() {
        return (-b + Math.pow(getDiscriminent(), 0.5)) / 2 * a;
    }

    public double getRoot2() {
        return (-b - Math.pow(getDiscriminent(), 0.5)) / 2 * a;
    }
}