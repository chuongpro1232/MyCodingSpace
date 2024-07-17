/*1.	Write a program to provide a menu for user to:
a.	Input a password (which is a string). Save it into a file namely "pwd.dat".
b.	Read the stored password from the file. Print it out to the console.
Example Run:
Password management program:
1. Save your password
2. Read your password
Your choice: 1
Enter the password: abc123
Saved to the file!
Additional: modify the program so that the password string may have spaces (e.g. “abc 123”).
*/
#include <iostream>
#include <fstream>
using std::cin;
using std::cout;

int main()
{
    int choice;
    std::string pwd;
    cout << "Password management program\n"
         << "1. save your password\n"
         << "2. Read your password\n"
         << "your choice: ";
    cin >> choice;
    std::fstream pwdfile;
    if (choice == 1) // save password
    {

        pwdfile.open("pwd.dat", std::ios::out);
        if (!pwdfile)
        {
            std::cerr << "fail to open the file";
            return -1;
        }
        std::string pwd;
        cout << "Enter the password: ";
        cin.ignore();
        std::getline(cin, pwd);

        pwdfile << pwd;
        pwdfile.close();
        cout << "Saved to the file" << std::endl;
    }
    else
    {
        pwdfile.open("pwd.dat", std::ios::in);
        if (!pwdfile)
        {
            std::cerr << "fail to open the file";
            return -1;
        }
        pwdfile >> pwd;
        getline(pwdfile, pwd);
        cout << "Your password is: " << pwd << std::endl;
        pwdfile.close();
    }
    return 0;
}