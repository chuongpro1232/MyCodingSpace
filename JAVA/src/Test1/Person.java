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

public abstract class Person {
    private String name;
    private String id;
    private String phoneNumber;
    private String address;
    private String email;
    private String gender;

    public Person(String name, String id, String phoneNumber, String address, String email, String gender) {
        this.name = name;
        this.id = id;
        this.phoneNumber = phoneNumber;
        this.address = address;
        this.email = email;
        this.gender = gender;
    }

    public Person() {
        this.name = null;
        this.id = null;
        this.phoneNumber = null;
        this.address = null;
        this.email = null;
        this.gender = null;
    }

    protected String getName() {
        return name;
    }

    protected void setName(String name) {
        this.name = name;
    }

    protected String getID() {
        return id;
    }

    protected void setID(String id) {
        this.id = id;
    }

    protected String getPhoneNumber() {
        return phoneNumber;
    }

    protected void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    protected String getAddress() {
        return address; 
    }
    
    protected void setAddress(String address) {
        this.address = address;
    }

    protected String getEmail() {
        return email; 
    } 
    

        this.email = email; 
    }

    protected String getGender() {
        return gender;
    }

    protected void setGender(String gender){
        this.gender =  gender; 
    } 
}
