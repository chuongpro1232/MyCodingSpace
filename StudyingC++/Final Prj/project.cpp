#include <iostream>
#include <vector>
#include "House.h"
#include "User.h"
#include "Renter.h"
    
using namespace std;

string username;

void reg(vector<User> &users)
{
    User m("n", "n", "n", "n"), q("q", "q", "q", "q");
    // User m;
    // m.signIn();

    users.push_back(m);

    users.push_back(q);
}

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

void printMember(vector<User> &members)
{
    for (User &mem : members)
    {
        mem.print();
    }
}

void addHouse(User *logIn, vector<House> &houses)
{
    // House h;
    // h.putHouse(logIn); // use this

    House h(logIn, "HN", 20, 2);
    houses.push_back(h);
}

void rentaHouse(vector<Renter> &renters, User *logIn, vector<House> &houses){

    string username;

    Renter r;

    cout << "Enter username of the house you want to rent: ";
    cin >> username;
    cin.sync();

    for (int i = 0; i < houses.size(); i++) {
        if(username == houses[i].getUsername()){
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

void acceptRequest(User *logIn, vector<Renter> &renters, vector<House> &houses){
    
    for(int i = 0; i < houses.size(); i++){
        if(logIn->getUsername() == houses[i].getUsername()){
            vector<Renter> renterRequested = houses[i].getRenterList();
            houses[i].printRenterRequested();
            string username;

            cout << "Enter the people(username) that you choose: ";
            cin >> username;
            cin.sync();

            for(int j = 0; j < renters.size(); j++){
                if(username == renters[j].getUsername()){
                    houses[i].acceptRenter(&renters[j]);
                }

                else{
                    renters[j].freeRequest();
                }
            }
        }
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

int main()
{
    // System sys ;
    vector<User> users;
    vector<House> houses;
    vector<Renter> renters;

    User *logIn;

    // sys.signIn();
    // sys.print();
    // obj.print();
    reg(users);
    printMember(users);
    logIn = log(users);
    logIn->print();

    // addHouse(logIn, houses); 
    addHouse(&users[0], houses);
    printHouse(houses);
    // members[0].print();
    rentaHouse(renters, logIn, houses);
    printRenter(renters);

    return 0;
}