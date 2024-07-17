package MockTest1;

import java.util.Date;

public abstract class Vehicle {
    private String VIN;
    private String marker;
    private String model;
    private int year;
    private String color;
    private String engineSize;
    private String fuelType;
    private String licensePlate;
    private Owner owner;
    private Date registrationDate;

    public Vehicle(String VIN, String marker, String model, int year, String color, String engineSize, String fuelType,
            String licensePlate, Owner owner, Date registrationDate) {
        this.VIN = VIN;
        this.marker = marker;
        this.model = model;
        this.year = year;
        this.color = color;
        this.engineSize = engineSize;
        this.fuelType = fuelType;
        this.licensePlate = licensePlate;
        this.owner = owner;
        this.registrationDate = registrationDate;
    }

    public Vehicle() {
        this.VIN = null;
        this.marker = null;
        this.model = null;
        this.year = 0;
        this.color = null;
        this.engineSize = null;
        this.fuelType = null;
        this.licensePlate = null;
        this.owner = null;
        this.registrationDate = null;
    }

    protected String getVIN() {
        return VIN;
    }

    protected String getMarker() {
        return marker;
    }

    protected String getModel() {
        return model;
    }

    protected int getYear() {
        return year;
    }

    protected String getColor() {
        return color;
    }

    protected String getEngineSize() {
        return engineSize;
    }

    protected String getFuelType() {
        return fuelType;
    }

    protected String getLicensePlate() {
        return licensePlate;
    }

    protected Owner getOwner() {
        return owner;
    }

    protected Date getRegistrationDate() {
        return registrationDate;
    }

    // SET
    protected void setVIN(String VIN) {
        this.VIN = VIN;
    }

    protected void setMarker(String marker) {
        this.marker = marker;
    }

    protected void setModel(String model) {
        this.model = model;
    }

    protected void setYear(int year) {
        this.year = year;
    }

    protected void setColor(String color) {
        this.color = color;
    }

    protected void setEngineSize(String engineSize) {
        this.engineSize = engineSize;
    }

    protected void setFuelType(String fuelType) {
        this.fuelType = fuelType;
    }

    protected void setLicensePlate(String licensePlate) {
        this.licensePlate = licensePlate;
    }

    protected void setOwner(Owner owner) {
        this.owner = owner;
    }

    protected void setRegistrationDate(Date registrationDate) {
        this.registrationDate = registrationDate;
    }
}
