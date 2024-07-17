package week3;

import java.util.Scanner;

public class ex4 {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        System.out.print("What is the value of a, b, c, d, e, f: ");
        double a = scan.nextDouble();
        double b = scan.nextDouble();
        double c = scan.nextDouble();
        double d = scan.nextDouble();
        double e = scan.nextDouble();
        double f = scan.nextDouble();
        LinearEquation linearEquation = new LinearEquation(a, b, c, d, e, f);
        if (linearEquation.isSolvable()) {
            System.out
                    .print("The X solution is " + linearEquation.getX() + " the Y solution is" + linearEquation.getY());
        } else {
            System.out.println("The equation has no solution");
        }
    }
}

class LinearEquation {
    private double a;
    private double b;
    private double c;
    private double d;
    private double e;
    private double f;

    public LinearEquation(double a, double b, double c, double d, double e, double f) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
        this.f = f;
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

    public double getD() {
        return d;
    }

    public double getE() {
        return e;
    }

    public double getF() {
        return f;
    }

    public boolean isSolvable() {
        return a * d - b * c != 0;
    }

    public double getX() {
        return (e * d - b * f) / (a * d - b * c);
    }

    public double getY() {
        return (a * f - e * c) / (a * d - b * c);
    }
}
