#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>

/*
    Command to compile:
    Get into the folder, then type: 
        g++ *.cpp     ; //it will create an executable file (a.out or a.exe by default)
        ./a.exe       ; //run the file on Windows (on MacOS/ Linux, we use ./a.out)
*/
#define FILENAME "userFile.dat"   // create file name D
#define HFILENAME "houseFile.dat" // create file name for house

#include "House.h"
#include "User.h"
#include "Renter.h"
#include "Review.h"

using namespace std;

string username;

#if 0
// admin
void System ::showAllUsers()
{
    cout << "\nAll users in the app: \n";
    for (User &use : users)
    {
        cout << use.username << " : " << use.password << " : " << use.fullname << " : " << use.phoneNum << " : " << use.credit << "\n";
    }
}

int System ::findHouse(string location, vector<House> &houses)
{ // base on location

    for (int i = 0; i < houses.size(); i++)
    {
        int res = houses[i].getLocation().compare(location);
        if (res != 0)
        {
            return -1;
        }
    }
    return 1;
}



bool reloadHouseData(vector<House> &houses, vector<User> &users, vector<Renter> &renters)
{

    std::ifstream houseFile;
    houseFile.open(HFILENAME, std::ios::in);

    if (!houseFile.is_open())
    {
        cout << "(There is no user in this app yet) \n";
        return false;
    }
    /* Reload data from the file */
    string username, location, description, price, minScore, avaivability, usernameR;

    while (!houseFile.eof())
    { // use .eof instead of that == "" way in w6

        // Read data from file
        getline(houseFile, username, ':'); // remember to put ':' at the end of every getline
        getline(houseFile, location, ':');
        getline(houseFile, description, ':');
        // read name until seeing ':' character
        getline(houseFile, price, ':');
        getline(houseFile, minScore, ':');
        getline(houseFile, avaivability, ':');
        getline(houseFile, usernameR, '\n');
        // read name until seeing ':' character
        if (start == "" || end == "")
        {
            break;
        }
        
        // Store into the house list
        houses.push_back(House(username, location, description, stof(price), stoi(minScore), stoi(avaivability), usernameR));

        for()

    
    }


    return true;
}




#endif
// lkjlkjlkjkjlkjlkjlkjkj
bool addHouse(User *logIn, vector<House> &houses)
{

    cout << "House's location: ";
    string location;
    do
    {
        getline(cin, location);
    } while (location == "");

    cout << "House's description: ";
    string description;
    do
    {
        getline(cin, description);
    } while (description == "");

    float price;
    cout << "House's price: ";
    cin >> price;
    cin.sync();

    int minScore;
    cout << "Minimum creditpoint for renter to rent: ";
    cin >> minScore;
    cin.sync();


    int avaivability = 1;

    houses.push_back(House(logIn, location, description, price, minScore, avaivability));
    cout << "House has been listed successfully! \n";
    return true;
}

void showHouseList(vector<House> &houses)
{
    cout << "\nAll houses in the app: \n";
    for (House &hou : houses)
    {
        hou.print4Guest();
    }
}

int findUser(string usernamee, vector<User> &users)
{

    for (size_t i = 0; i < users.size(); i++)
    {
        int res = users[i].getUsername().compare(usernamee);
        if (res == 0)
        {
            return -1;
        }
    }
    return 1;
}

bool addUser(vector<User> &users)
{
    string username;
    cout << "Input username: ";
    cin >> username;
    int check = findUser(username, users);
    if (check == -1)
    { // member is already in the system
        cout << "This name is already taken, please choose another username!\n";
        return false;
    }
    else
    { // Add new user
        cout << "Your full name: ";
        string fullname;
        do
        {
            getline(cin, fullname);
        } while (fullname == "");

        string phoneNum;
        cout << "Your phone number: ";
        cin >> phoneNum;
        cin.sync();

        string password;
        cout << "Create a password: ";
        cin >> password;
        cin.sync();

        float credit = 500;

        users.push_back(User(username, password, fullname, phoneNum, credit));
        cout << "Member account is successfully created! \n";
        return true;
    }
}

void searchHouse(vector<House> &houses)
{
    string location;

    cout << "Enter location you want to search: ";
    cin >> location;
    cin.sync();

    short flag = 0;
    for (size_t i = 0; i < houses.size(); i++)
    {
        int res = houses[i].getLocation().compare(location);
        if (res == 0) // put && user.credit == minScore here
        {
            houses[i].print();
            flag = 1;
        }
        if (!flag)
        {
            cout << "invalid location";
        }
    }
}

// save and load file
bool saveAllusers(vector<User> &users)
{
    ofstream userFile;
    userFile.open(FILENAME, std::ios::out);
    if (!userFile.is_open())
    {
        cout << "Fail to create/open file \n";
        return false;
    }
    // Store in the file
    for (User &use : users)
    {
        userFile << use.getUsername() << ":" << use.getPassword() << ":" << use.getFullname() << ":" << use.getPhoneNum() << ":" << use.getCredit() << "\n";
    }
    return true;
}

bool reloadUserData(vector<User> &users)
{
    ifstream userFile;
    userFile.open(FILENAME, std::ios::in);

    if (!userFile.is_open())
    {
        cout << "(There is no user in this app yet) \n";
        return false;
    }

    /* Reload data from the file */
    string username, password, fullname, phoneNum, credit;

    while (1)
    {
        // Read data from file
        getline(userFile, username, ':');
        getline(userFile, password, ':');
        getline(userFile, fullname, ':');
        // read name until seeing ':' character
        getline(userFile, phoneNum, ':');
        getline(userFile, credit, '\n');

        if (username == "" || fullname == "" || password == "" || phoneNum == "" || credit == "")
        {
            break;
        }

        // Store into the student list
        users.push_back(User(username, password, fullname, phoneNum, std::stof(credit)));
    }

    return true;
}

bool saveAllhouses(vector<House> &houses)
{
    ofstream houseFile;
    houseFile.open(HFILENAME, std::ios::out); // remember to use ::app to append
    if (!houseFile.is_open())
    {
        cout << "Fail to create/open file \n";
        return false;
    }

    // Store in the file
    for (House &hou : houses)
    { // remember to save data in the right order
        houseFile << hou.getUsername() << ":" << hou.getLocation() << ":" << hou.getDescription() << ":" << hou.getPrice() << ":" << hou.getMinScore() << ":" << hou.getAvaivability() << ":" << hou.getUsernameR() << "\n";
    }
    return true;
}

//
User *log(vector<User> &users)
{
    string username;
    string password;
    short flag = 0;

    cout << "Username: ";
    cin >> username;
    cin.sync();

    cout << "Password: ";
    cin >> password;
    cin.sync();

    for (User &user : users)
    {
        if (user.logIn(username, password))
        {
            cout << "Correct" << endl;
            flag = 1;
            return &user;
        }
    }
    if (flag == 0)
    {
        cout << "Wrong username or password" << endl;
        return nullptr;
    }
    return nullptr;
}

void unlistHouse(User *logIn, vector<House> &houses)
{
    for (auto it = houses.begin(); it != houses.end(); it++)
    {
        if (logIn->getUsername() == it->getUsername())
        {
            houses.erase(it);
            cout << "House has been unlisted successfully" << endl;
        }
        else
        {
            cout << "You do not have any house yet" << endl;
        }
    }
}

void rentaHouse(User *logIn, vector<Renter> &renters, vector<House> &houses)
{

    string username;

    Renter r;

    cout << "Enter username of the house you want to rent: ";
    cin >> username;
    cin.sync();

    for (size_t i = 0; i < houses.size(); i++)
    {
        if (username == houses[i].getUsername())
        {
            r.requestHouse(logIn, &houses[i]);
            houses[i].addRenter(r);
            // houses[i].printRenterRequested(); //check only
            cout << "Requested successfully" << endl;

            break;
        }
        cout << "Cannot find the require house" << endl;
    }

    renters.push_back(r);
}

void viewRequest(User *logIn, vector<House> &houses)
{
    for (size_t i = 0; i < houses.size(); i++)
    {
        if (logIn->getUsername() == houses[i].getUsername())
        {
            houses[i].printRenterRequested();
        }
        else
        {
            cout << "Currently you do not have any house" << endl;
        }
    }
}

void acceptRequest(User *logIn, vector<Renter> &renters, vector<House> &houses)
{

    for (size_t i = 0; i < houses.size(); i++)
    {
        if (logIn->getUsername() == houses[i].getUsername())
        {
            // vector<Renter> renterRequested = houses[i].getRenterList();
            houses[i].printRenterRequested();
            string username;

            cout << "Enter the people(username) that you choose: ";
            cin >> username;
            cin.sync();

            for (size_t j = 0; j < renters.size(); j++)
            {
                if (username == renters[j].getUsername())
                {
                    houses[i].acceptRenter(&renters[j]);
                    renters[j].acceptOccupy(&houses[i]);
                }

                else
                {
                    renters[j].freeRequest();
                }
            }
            cout << "Accept request successfully!" << endl;
        }
        else
        {
            cout << "Currently you do not have any house" << endl;
        }
    }
}

// review
void writeReviewRenter2House(vector<Review> &reviews, vector<Renter> &renters, User *logIn)
{
    Review re;
    for (size_t i = 0; i < renters.size(); i++)
    {
        if (logIn->getUsername() == renters[i].getUsername())
        {
            if (renters[i].getOccupy() != nullptr)
            {
                int score;
                string comment;

                cout << "Enter score: ";
                cin >> score;
                cin.sync();

                cout << "Type in comment: ";
                cin >> comment;
                cin.sync();

                re.addReviewRenter2House(&renters[i], renters[i].getOccupy(), score, comment);
            }

            else
            {
                cout << "Currently you do not rent any house!" << endl;
            }
        }

        else
        {
            cout << "Currently you do not rent any house!" << endl;
        }
    }

    reviews.push_back(re);
}

void writeReviewHouse2Renter(vector<Review> &reviews, vector<House> &houses, User *logIn)
{
    Review re;
    for (size_t i = 0; i < houses.size(); i++)
    {
        if (logIn->getUsername() == houses[i].getUsername())
        {
            if (houses[i].getRenter() != nullptr)
            {
                int score;
                string comment;

                cout << "Enter score: ";
                cin >> score;
                cin.sync();

                cout << "Type in comment: ";
                cin >> comment;
                cin.sync();

                re.addReviewHouse2Renter(&houses[i], houses[i].getRenter(), score, comment);
            }

            else
            {
                cout << "Currently you do not rent any house!" << endl;
            }
        }

        else
        {
            cout << "Currently you do not rent any house!" << endl;
        }
    }

    reviews.push_back(re);
}

// user for admin
void printMember(vector<User> &members)
{
    for (User &mem : members)
    {
        mem.print();
    }
}

void printRenter(vector<Renter> &renters)
{
    for (Renter &r : renters)
    {
        r.print();
    }
}

void printHouse(vector<House> &houses)
{
    for (House &house : houses)
    {
        house.print();
    }
}

#if 0 // only for testing feature
int main()
{
    // System sys ;
    vector<User> users;
    vector<House> houses;
    vector<Renter> renters;
    vector<Review> reviews;

    User *logIn;
    // Renter *logRenter;
    // House *logHouse;

    // sys.signIn();
    // sys.print();
    // obj.print();
    // reg(users);

    reloadUserData(users);
    printMember(users);
    // logIn = log(users);
    // logIn->print();

    // addHouse(logIn, houses);
    addHouse(&users[0], houses); // add as n
    printHouse(houses);
    // members[0].print();
    // rentaHouse(renters, logIn, houses);
    rentaHouse(renters, &users[1], houses);
    printRenter(renters);

    acceptRequest(&users[0], renters, houses);

    writeReviewRenter2House(reviews, renters, &users[1]);

    writeReviewHouse2Renter(reviews, houses, &users[0]);

    reviews[0].print();
    reviews[1].print();

    //     bool System ::saveAllhouses()
    // {
    // ofstream houseFile;
    // houseFile.open(HFILENAME, std::ios::out); // remember to use ::app to append
    // if (!houseFile.is_open())
    // {
    //     cout << "Fail to create/open file \n";
    //     return false;
    // }
    // // Store in the file
    // for (House &hou : houses)
    // { // remember to save data in the right order
    //     houseFile << hou.getUser() << ":" << hou.getLocation() << ":" << hou.getPrice() << ":" << hou.getMinScore() << ":" << hou.getAvaivability() << ":" << hou.getRenter() << ":" << hou.getRenterList() << "\n";
    // }
    // return true;
    // }

    saveAllusers(users);

    return 0;
}
#endif

#if 1 // USE this
int main()
{
    string adminUsername("admin");
    string adminPassword("123");

    vector<User> users;
    vector<House> houses;
    vector<Renter> renters;
    vector<Review> reviews;

    cout << "\nEEET2482/COSC2082 ASSIGNMENT\n"
         << "VACATION HOUSE EXCHANGE APPLICATION\n\n"
         << "Instructors: Mr. Linh Tran & Phong Ngo\n"
         << "Group: 12\n"
         << "s3938006, Huynh Quang Dong \n"
         << "s3924704, Huynh Ngoc Duy \n"
         << "s3957386, Tran Thanh Tu \n"
         << "s3929351, Nguyen Hoang \n"
         << "s3665018, Shu Chang Bean\n\n";

    cout << "-----------------------------------------------------------------------\n";
    try
    {
        reloadUserData(users);
    }
    catch (invalid_argument)
    {
        cerr << "no user's data has been found!\n";
    }


    cout << "Use the app as 1. Guest   2. Member   3. Admin\n"
         << "Enter your choice: ";
    int choice;
    cin >> choice;

    if (choice == 2)
    {
        cout << "-----------------------------------------------------------------------\n";
        
        User *logIn;
        logIn = log(users);

        cout << "1. Add house  2. Unlist house  3. Request a house  4. Search houses  5. View request  6. Accept request\n"
                 << "Enter your choice: ";

        int choiceA;
        cin >> choiceA;
        cin.sync();

        if(choiceA == 1){
            addHouse(logIn, houses);
        }

        else if(choiceA == 2){
            unlistHouse(logIn, houses);
        }

        else if(choiceA == 3){
            rentaHouse(logIn, renters, houses);
        }

        else if(choiceA == 4){
            searchHouse(houses);
        }

        else if(choiceA == 5){
            viewRequest(logIn, houses);
        }

        else if(choiceA == 6){
            acceptRequest(logIn, renters, houses);
        }
    }
    
    else if (choice == 3)
    {
        string adminname, adminpwd;
        cout << "Enter admin username: ";
        cin >> adminname;
        cout << "Enter admin password: ";
        cin >> adminpwd;
        int checkname = adminname.compare(adminUsername);
        int checkpwd = adminpwd.compare(adminPassword);

        if (checkname == 0 && checkpwd == 0)
        {
            cout << "-----------------------------------------------------------------------\n";
            cout << "Welcome back admin!\n";
            cout << "1. view members's information        2. view houses's information  \n"
                 << "Enter your choice: ";
            int choiceA;
            cin >> choiceA;
            if (choiceA == 1)
            {
                printMember(users);
            }
            else if(choiceA == 2){
                printHouse(houses);
            }
        }
        else
        {
            cout << "Wrong username or password! the system will automatically exist.";
        }
    }
    
    else if (choice == 1)
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
                showHouseList(houses);
            }

            else if (choice == 2)
            {
                addUser(users);
                if (!saveAllusers(users))
                {
                    cout << "Error: Fail to save data for your app \n";
                }
                cout << "-----------------------------------------------------------------------\n";
                break;
            }

            else
            { // Save all data before exit
                if (saveAllusers(users))
                {
                    cout << "Error: Fail to save data for your app \n";
                }
                cout << ">>>> Bye. Have a good day ! <<<<";
                break;
            }
        }
    }
    return 0;
}
#endif