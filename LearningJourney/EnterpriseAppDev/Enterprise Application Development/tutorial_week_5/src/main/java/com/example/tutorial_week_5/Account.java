package com.example.tutorial_week_5;

public class Account {
    private String number;
    private double balance;

    private Customer customer;

    public Account(String number, double balance) {
        this.number = number;
        this.balance = balance;
    }

    public String getNumber() {
        return number;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public void deposit(double amount){
        this.balance += amount;
    }
    public boolean withdraw(double amount){
        if (this.balance>=amount){
            this.balance -=amount;
            return true;
        }
        else{
            return false;
        }

    }
}
