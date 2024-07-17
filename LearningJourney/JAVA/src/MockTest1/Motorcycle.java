package MockTest1;

import java.util.Date;

public class Motorcycle extends Vehicle{
    private int numOfWheels;
 
    public Motorcycle(String vin, String make, String model, int year, String color, String engineSize, String fuelType, String licensePlate, Owner owner, Date registrationDate, int numOfWheels) {
        super(vin, make, model, year, color, engineSize, fuelType, licensePlate, owner, registrationDate);
        this.numOfWheels = numOfWheels;
            
    }

    public Motorcycle() {
        super();
        this.numOfWheels = 0;
    }

    public int getNumOfWheels() {
        return numOfWheels;
    }

    public void setNumOfWheels(int numOfWheels) {
        this.numOfWheels = numOfWheels;
    }
}
