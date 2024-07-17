package MockTest1;

public class Organization extends Owner {
    Person representative;

    public Organization(String name, String phone, String email, String address, Person representative) {
        super(name, phone, email, address);
        this.representative = representative;
    }

    public Organization() {
        super();
        this.representative = null;
    }
}
