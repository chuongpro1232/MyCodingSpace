package MockTest1;

import java.util.Date;

public class Car extends Vehicle {
    private int seatCapacity;

    public Car(String VIN, String maker, String model, int year, String color, String engineSize, String fuelType,
            String licensePlate, Owner owner, Date registrationDate, int seatCapacity) {
        super(VIN, maker, model, year, color, engineSize, fuelType, licensePlate, owner, registrationDate);
        this.seatCapacity = seatCapacity;
    }

    public Car() {
        super();
        this.seatCapacity = 0;
    }

    protected int getSeatCapacity() {
        return seatCapacity;
    }

    protected void setSeatCapacity(int seatCapacity) {
        this.seatCapacity = seatCapacity;
    }
}
