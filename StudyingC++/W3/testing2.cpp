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
    string name;

    Student(string nameVal = "", int scoreVal = 0, string pwdVal = "")
        : name(nameVal), score(scoreVal), password(pwdVal) {}

    void showInfo()
    {
        cout << "Name = " << name
             << ", Score = " << score << "\n";
    }

    int getScore() { return score; }

    /* Q3:  Method to change password */
    int changePwd()
    {
        std::fstream myfile;

        // Load password value from file if it is blank
        if (password == "")
        {
            // Open the password file and read
            myfile.open(name + ".dat", std::ios::in);

            if (!myfile)
            {
                std::cerr << "Fail to open " << name + ".dat\n";
            }
            else
            {
                getline(myfile, password);
                myfile.close();
            }
        }

        if (password == "")
        { // No previous password (still blank after loading)
            cout << "No existing password. \nPlease set your password: ";
        }
        else
        {
            /* there is an existing password */
            // Ask user to input password
            string inPwd;
            cout << "Enter your previous password: ";
            getline(cin, inPwd);

            // Check with previous password store in the file
            if (inPwd == password)
            { //
                cout << "Enter your new password: ";
            }
            else
            {
                cout << "Wrong password! \n";
                return -1;
            }
        }

        // Read new password from console and save to the file
        myfile.open(name + ".dat", std::ios::out);
        getline(cin, password);

        myfile << password;
        myfile.close();
        cout << "Save your new password successfully! \n";

        return 0; // no error
    }
};

int main()
{
    // Test the class method
    Student stu("Thu Nguyen", 80);
    stu.changePwd();
    stu.changePwd();

    return 0;
}