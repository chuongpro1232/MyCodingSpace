/* Source file:
 *  Definitions of functions/ methods for the module
 */

#include <iostream>
#include "User.h"

using namespace std;

//Definition

//Constructor
// User::User

// User::User(string usernameVal, string passwordVal, string fullnameVal, string phoneNumVal, float creditVal): 
// username(usernameVal), password(passwordVal), fullname(fullnameVal), phoneNum(phoneNumVal), credit(creditVal) {
//     cout << "constructor " << usernameVal << endl;
// }

// User::User(string usernameVal, string passwordVal, string fullnameVal, string phoneNumVal, float creditVal) 
// {this->username = usernameVal; this->password = passwordVal; this->fullname = fullnameVal; this->phoneNum = phoneNumVal; this->credit = creditVal;}

//Method
void User::signIn()
{

    cout << "Name: ";
    cin >> username;
    cin.sync();

    cout << "Password: ";
    cin >> password;
    cin.sync();

    cout << "fullname: ";
    cin >> fullname;
    cin.sync();

    cout << "Phone number: ";
    cin >> phoneNum;
    cin.sync();

    credit = 500;
}

bool User::logIn(string name, string pass)
{
    if (name != username)
    {
        return false;
    }
    else if (pass != password)
    {
        return false;
    }
    return true;
}

void User::print()
{
    cout << "Show: " << username << " " << password << fullname << phoneNum << credit << endl;
}