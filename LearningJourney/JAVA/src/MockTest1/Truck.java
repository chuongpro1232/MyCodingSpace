package MockTest1;

import java.util.Date;

public class Truck extends Vehicle {
    private int loadCapacity;

    public Truck(String vin, String make, String model, int year, String color, String engineSize, String fuelType,
            String licensePlate, Owner owner, Date registrationDate, int loadCapacity) {
        super(vin, make, model, year, color, engineSize, fuelType, licensePlate, owner, registrationDate);
        this.loadCapacity = loadCapacity;
    }

    public Truck() {
        super();
        this.loadCapacity = 0;
    }

    protected int getLoadCapacity() {
        return loadCapacity;
    }

    protected void setLoadCapacity(int loadCapacity) {
        this.loadCapacity = loadCapacity;
    }
}
