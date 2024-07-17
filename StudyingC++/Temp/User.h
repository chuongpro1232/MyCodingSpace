#ifndef __USER_H__
#define __USER_H__
/* make sure that this file will be included only once in compilation process
   (when the keyword __USER_H__ is not defined before)
*/

#include <iostream>

using namespace std;

class User
{
private:
    string username;
    string password;
    string fullname;
    string phoneNum;

    float credit;

public:
    // constructor
    User (){
        this->username = "";
        this->password = "";
        this->fullname = "";
        this->phoneNum = "";

        this->credit = 0;
    };

    User(string usernameVal, string passwordVal, string fullnameVal, string phoneNumVal, float creditVal){
        this->username = usernameVal;
        this->password = passwordVal;
        this->fullname = fullnameVal;
        this->phoneNum = phoneNumVal;

        this->credit = creditVal;
    }
   
   
    // User(string usernameVal = "", string passwordVal = "", string fullnameVal = "", string phoneNumVal = "", float creditVal = 500);
    

    void signIn();

    // void changeName(string newName) {
    //     this->username = newName;
    // }

    bool logIn(string name, string pass);

    // ostream& <<(const ostream &o) const {
    //     o << this->username << endl;
    //     o << this->password << endl;
    //     return o;
    // }

    //get value
    string getUsername(){
        return username;
    }

    string getPassword(){
        return password;
    }

    string getFullname(){
        return fullname;
    }

    string getPhoneNum(){
        return phoneNum;
    }

    int getCredit(){
        return credit;
    }
    
    void print();
};

#endif