package videostoremanager.witchcraftprj.Items;

public enum RentalType {
    RECORD("Records"),
    DVD("DVDs"),
    GAME("Games");

    private String Rent_value;

    RetalType(String Rent_value) {
        this.Rent_value = Rent_value;
    }
    public String getRent_value(){
        return Rent_value;
    }

    public static RentalType fromValue(String Rent_value){
        for (RentalType rentalType : RentalType.values()){
            if (rentalType.getRent_value().equalsIgnoreCase(Rent_value)){
                return rentalType;
            }
        }
    }

}
