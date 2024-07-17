/*3.	From the Student class in question 2, add another private string attribute namely password. Write a method for the class namely change_pwd() to allow people to change their password as below and test it in main function.
a.	If there is no existing password (no name.dat file, whereas name is student name, or no content in the file), allow them to provide value for the password. Save it into the file (name.dat).
b.	If there is an existing password, ask them to enter their previous password to check. If it is matched, save the new password into their file.*/
#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::string;
class Student
{
private:
    int score;
    string password;

public:
    std::string name;

    Student(string nameVal = "", int scoreVal = 0, string pwdVal = "")
        : name(nameVal), score(scoreVal), password(pwdVal) {}
    int getScore()
    {
        return score;
    }

    int password_change()
    {
        std::fstream pwdfile;
        if (password == "")
        {
            pwdfile.open(name + ".dat", std::ios::in);
            if (!pwdfile)
            {
                std::cerr << "can't open the file";
            }
            else
            {
                getline(pwdfile, password);
                pwdfile.close();
            }
        }
        if (password == "")
        {
            pwdfile.open(name + ".dat", std::ios::out);
            cout << "enter the password: ";
            // cin.ignore();
            std::getline(cin, password);
            pwdfile << password;
            pwdfile.close();
            cout << "Saved to the file" << std::endl;
        }
        else
        {
            string pwdcheck;
            pwdfile.open(name + ".dat", std::ios::in);
            std::getline(pwdfile, password);
            cout << "enter your password: ";
            cin >> pwdcheck;
            if (pwdcheck == password)
            {
                pwdfile.open(name + ".dat", std::ios::out);
                cout << "enter your new password: ";
                cin.ignore();
                std::getline(cin, password);
                pwdfile << password;
                pwdfile.close();
                cout << "Saved to the file" << std::endl;
            }
            else if (pwdcheck != password)
            {
                cout << "wrong password";
                return -1;
            }
        }

        return 0;
    }
};

int main()
{
    Student st1("Ningni", 10);
    st1.password_change();
}