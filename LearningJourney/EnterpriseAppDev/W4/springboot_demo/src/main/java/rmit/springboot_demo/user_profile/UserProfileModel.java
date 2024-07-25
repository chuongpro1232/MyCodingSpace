package rmit.springboot_demo.user_profile;

public class UserProfileModel implements UserShippingAddress {
    private String name;
    private int id;
    private int age;
    private String gender;
    private double balance;
    private String address;
    
    public UserProfileModel(String name, int id, int age, String gender, double balance, String address){
        this.name = name;
        this.id = id;
        this.age = age;
        this.gender = gender;
        this.balance = balance;
        this.address = address;
    }

    static UserProfileModel getDefaultInvalidUser() {
        return new UserProfileModel (
            "N/A",
            -1,
            -1,
            "",
            0,
            "N/A"
        );
    }
    public String getName() {
        return name;
    }
    public void setName(String Name){
        this.name = name;
    }
    public int getId() {
        return id;
    }
    public void setId(int id){
        this.id = id;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age){
        this.age =age;
    }
   
    public String getGender() {
        return gender;
    }
    public void setGender(String gender){
        this.gender = gender;
    }
    public double getBalance() {
        return balance;
    }
    public void setBalance(double balance){
        this.balance = balance;
    }
    public String getAddress() {
        return address;
    }
    public void setAddress(String address){
        this.address = address;
    }

}
