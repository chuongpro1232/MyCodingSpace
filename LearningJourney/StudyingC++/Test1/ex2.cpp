/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2022-3
  Lab Assessment: 1
  Author: Tran Thanh Tu
  ID: S3957386
  Compiler used: 8.1.0
  Created  date: 26/11/2022
  Acknowledgement: List the resources that you use to complete this assessment (write 'None' if you don't use any).
*/

#include <iostream>
using std::cin;
using std::cout;
using std::string;

class EWallet
{
public:
    string name;
    double balance = 0; // declared balance as double
    bool pay(double amount, string coupon = "...")
    {
        if (coupon == "BLACKFRIDAY")
        {
            amount *= 70 / 100;
        }
        if (this->balance >= amount)
        {
            cout << "You have payed!!!" << std::endl;
            this->balance = this->balance - amount;
            // cout << amount << std::endl
            //      << balance << std::endl;
            return 1;
        }
        else
        {
            cout << "You don't have enough money!!";
            return 0;
        }
    }
    friend EWallet &operator>>(double n, EWallet &obj)
    {
        obj.balance += n;
        return obj;
    }
};

class User
{
public:
    string name;
    string pwd;
    EWallet acc;
    double money()
    {
        return this->acc.balance;
    }
    void setup()
    {
        cout << "name: " << std::endl;
        string wl1;
        cin >> wl1;
        name = wl1;
    }
};
int main()
{
    EWallet wl1;
    23300 >> wl1;
    cout << wl1.balance << std::endl;

    wl1.pay(50, "X");
    cout << wl1.balance << std::endl;
    return 0;
}