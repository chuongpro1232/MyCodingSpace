package week3;

import java.util.GregorianCalendar;

public class ex1 {

    public static void main(String args[]) {
        GregorianCalendar calendar = new GregorianCalendar();
        System.out.printf("The time is (yy/mm/dd): " + calendar.get(calendar.YEAR) + "/" + calendar.get(calendar.MONTH)
                + "/" + calendar.get(calendar.DAY_OF_MONTH));
        calendar.setTimeInMillis(1234567898765L);

        System.out.printf("\nThe time after elpase 12345678765L is (yy/mm/dd): " + calendar.get(calendar.YEAR) + "/"
                + calendar.get(calendar.MONTH)
                + "/" + calendar.get(calendar.DAY_OF_MONTH));
    }
}
