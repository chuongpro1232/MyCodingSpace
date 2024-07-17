package MockTest1;

import java.util.Date;

public abstract class Owner {
    private String name;
    private String phone;
    private String email;
    private String address;

    public Owner(String name, String phone, String email, String address) {
        this.name = name;
        this.phone = phone;
        this.email = email;
        this.address = address;
    }

    public Owner() {
        this.name = null;
        this.phone = null;
        this.email = null;
        this.address = null;
    }

    protected String getName() {
        return name;
    }

    protected String getPhone() {
        return phone;
    }

    protected String getEmail() {
        return email;
    }

    protected String getAddress() {
        return address;
    }

    protected void setName(String name) {
        this.name = name;
    }

    protected void setPhone(String phone) {
        this.phone = phone;
    }

    protected void setEmail(String email) {
        this.email = email;
    }

    protected void setAddress(String address) {
        this.address = address;
    }
}
