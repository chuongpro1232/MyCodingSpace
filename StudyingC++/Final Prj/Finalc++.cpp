#include <iostream>
#include <vector>
#include <fstream>
using std::cin;
using std::cout;
using std::string;
using std::vector;
#include <cstring>
#define FILENAME "memberFile.dat"

class Review
{
private:
    int score;
    string comment;

public:
    Review(int score = 0, string comment = "")
        : score(score), comment(comment) {}
    void showInfoR()
    {
        cout << "score = " << score      // edit it to average
             << "comment = " << comment; // list of comment
        cout << "\n";
    }
    friend class Member;
    friend class House;
};

class House
{
private:
    // vector<Review*> HouseReview;
    // vector<Member*> Request;
    string availablePeriod;
    int consumingPoint;
    int MinRequire;
    string location;
    string description;
    // vector<Member*> CurrentRenter;

public:
    House(string availablePeriod = "", int consumingPoint = 0, int MinRequire = -10, string location = "", string description = "") // vector<Review*> HouseReview = {}, vector<Member*> Request = {}, vector<Member*> CurrentRenter = {}
        : availablePeriod(availablePeriod), consumingPoint(consumingPoint), MinRequire(MinRequire),
          location(location), description(description)
    {
    } // CurrentRenter(CurrentRenter), HouseReview(HouseReview), Request(Request) {}

    void showPublic()
    {
        cout << "Location = " << location
             << ", description = " << description;
        cout << "\n";
    }

    void showDetail()
    {
        cout << "Location = " << location
             << ", description = " << description;
        // << ", List of request : "

        // for (Member *listR: Request) {
        //    listR.showInfo;
        //}

        cout << "\n";
    }

    friend class Member;
    friend class Review;
};

class Member
{
protected:
    int creditPoint;
    string username;
    string password;
    // vector <House*> AvailableHouses;
    // vector<Review*> MemReview;

public:
    string fullname;
    string phone;
    Member(string username = "", string fullname = "", string password = "", string phone = "", int creditPoint = 0) // vector <House*> AvailableHouses = {}, vector<Review*> MemReview = {}
        : username(username), fullname(fullname), password(password), phone(phone), creditPoint(creditPoint)
    {
    } // AvailableHouses(AvailableHouses), MemReview(MemReview)

    friend class System; // declare friend to grant access
};

class System
{
private:
    vector<Member> members{};

public:
    System() {} // constructor

    int findMember(string username)
    {

        for (int i = 0; i < members.size(); i++)
        {
            int res = members[i].username.compare(username);
            if (res == 0)
            {
                return 1;
            }
        }
        return -1;
    }

    bool addMember()
    {
        string username;
        cout << "Input username: ";
        cin >> username;
        int check = findMember(username);
        if (check > 0)
        { // Student is already in the system
            cout << "This name is already taken, please choose another name!\n";
            return false;
        }
        else
        { // Add new student
            cout << "Your full name: ";
            string fullname;
            do
            {
                getline(cin, fullname);
            } while (fullname == "");

            string phone;
            cout << "Your phone number: ";
            cin >> phone;

            string password;
            cout << "Create a password: ";
            cin >> password;

            int creditPoint = 500;

            members.push_back(Member(username, fullname, password, phone, creditPoint));
            cout << "Member account is successfully created! \n";
            return true;
        }
    }

    bool saveAllmembers()
    {
        std::ofstream memberFile;
        memberFile.open(FILENAME, std::ios::out);
        if (!memberFile.is_open())
        {
            cout << "Fail to create/open file \n";
            return false;
        }
        // Store in the file
        for (Member &mem : members)
        {
            memberFile << mem.username << " : " << mem.fullname << " : " << mem.password << " : " << mem.phone << " : " << mem.creditPoint << "\n";
        }
        return true;
    }

    bool reloadMemberData()
    {
        std::ifstream memberFile;
        memberFile.open(FILENAME, std::ios::in);

        if (!memberFile.is_open())
        {
            cout << "Fail to open file \n";
            return false;
        }

        /* Reload data from the file */
        string username, fullname, password, phone, creditpointString;

        while (1)
        {
            // Read data from file
            getline(memberFile, username);
            getline(memberFile, fullname, ':');
            // read name until seeing ':' character
            getline(memberFile, password);
            getline(memberFile, phone);
            getline(memberFile, creditpointString);

            if (username == "" || fullname == "" || password == "" || phone == "" || creditpointString == "")
            {
                break;
            }

            // Store into the student list
            members.push_back(Member(username, fullname, password, phone, std::stoi(creditpointString)));
        }

        return true;
    }

    void showAllMembers()
    {
        cout << "\nAll members in the app: \n";
        for (Member &mem : members)
        {
            cout << mem.fullname << " : " << mem.phone << " : " << mem.username << " : " << mem.password << " : " << mem.creditPoint << "\n";
        }
    }

    friend class House;
    friend class Review;
    friend class Member;
};

int main()
{
    vector<Member> members;
    System sys;
    cout << "\nEEET2482/COSC2082 ASSIGNMENT\n"
         << "VACATION HOUSE EXCHANGE APPLICATION\n\n"
         << "Instructors: Mr. Linh Tran & Phong Ngo\n"
         << "Group: Group Name\n"
         << "sXXXXXXX, Student Name\n"
         << "sXXXXXXX, Student Name\n"
         << "sXXXXXXX, Student Name\n"
         << "sXXXXXXX, Student Name\n"
         << "sXXXXXXX, Student Name\n\n";

    cout << "-----------------------------------------------------------------------\n";
    cout << "Use the app as 1. Guest   2. Member   3. Admin\n"
         << "Enter your choice: ";
    int choice;
    cin >> choice;

    // if (choice == 1) {
    //  std::fstream memberfile;
    //     memberfile.open("Member.dat", std::ios::out);
    //     if (!memberfile) {
    //             cout << "Fail to create/open file \n";
    //             return -1;
    //       }
    if (choice == 2)
    {
        cout << "unavailable feature! we are working on this";
    }
    else if (choice == 3)
    {
        cout << "unavailable feature! we are working on this";
    }
    else
    {
        while (1)
        {
            cout << "-----------------------------------------------------------------------\n";
            cout << "1. view all house details    2. Register to become a member    3. exist\n"
                 << "Enter your choice: ";
            cin >> choice;
            cout << "-----------------------------------------------------------------------\n";
            if (choice == 1)
            {
                cout << "unavailable feature! we are working on this";
            }

            else if (choice == 2)
            {
                sys.addMember();
            }
            else
            { // Save all data before exit
                if (!sys.saveAllmembers())
                {
                    cout << "Error: Fail to save data for your app \n";
                }
                cout << "* Bye. Have a good day ! *";
                break;
            }
        }
    }
    return 0;
}