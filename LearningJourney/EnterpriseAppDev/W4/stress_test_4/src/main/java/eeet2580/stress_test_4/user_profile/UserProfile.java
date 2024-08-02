package eeet2580.stress_test_4.user_profile;

public class UserProfile {
    private String name;
    private int id;
    private double balance;
    public UserProfile (String name, int id, double balance){
        this.name = name;
        this.id = id;
        this.balance = balance;
    }
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }
    public int getId(){
        return id;
    }
    public void setId(int id){
        this.id = id;
    }
    public double getbalance(){
        return balance;
    }
    public void setbalance(double balance){
        this.balance = balance;
    }
}

