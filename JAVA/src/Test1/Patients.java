/*
  RMIT University Vietnam
  Course: INTE2512 Object-Oriented Programming
  Semester: 2023A
  Assessment: Test 1
  Author: Tran Thanh Tu
  ID: S3957386
  Created  date: 15/04/2023
  Acknowledgement: None
*/

package Test1;

import java.util.Date;

public class Patients extends Person {
    String sickness;
    Date dayIn;

    public Patients(String name, String id, String phoneNumber, String address, String email, String gender,
            String sickness, Date dayIn) {
        super(name, id, phoneNumber, address, email, gender);
        this.sickness = sickness;
        this.dayIn = dayIn;
    }

    public Patients() {
        super();
        this.sickness = null;
        this.dayIn = null;
    }

    protected String getSickness() {
        return sickness;
    }

    protected void setSickness(String sickness) {
        this.sickness = sickness;
    }

    protected Date getDayIn() {
        return dayIn;
    }

    protected void setDayin(Date dayIn) {
        this.dayIn = dayIn;
    }
}
