/* Source file:
 *  Definitions of functions/ methods for the module
 */

#include <iostream>
#include <vector>

#include "House.h"
#include "Renter.h"
#include "User.h"

using namespace std;

// Definition

// constructor

House::House()
{
    this->user = nullptr;

    this->location = "";
    this->price = 0;
    this->minScore = 0;
    this->avaivability = false;

    this->renter = nullptr;
    // vector<Renter> rentersRequested;
}

House::House(User *userVal, string locationVal, string descriptionVal, float priceVal, int minScoreVal, int avaivabilityVal)
{
    this->user = userVal;

    this->username = userVal->getUsername();

    this->location = locationVal;
    this->description = descriptionVal;
    this->price = priceVal;
    this->minScore = minScoreVal;
    this->avaivability = avaivabilityVal;

    this-> usernameR = "";
    this->renter = nullptr;
}


// Method
void House::putHouse(User *logIn)
{

    user = logIn;

    cout << "Location: ";
    cin >> location;
    cin.sync();

    cout << "Price ";
    cin >> price;
    cin.sync();

    cout << "Minimal require score: ";
    cin >> minScore;
    cin.sync();

    avaivability = true;
}

void House::print()
{
    if (user != nullptr)
    {
        cout << "Username: " << username << ", Location: " << location << ", Description: " << description << endl;
        cout << "Price: " << price << ", Minimum score: " << minScore << ", Avaivability (0 = NO, 1 = YES): " << avaivability << endl;
    }
}

void House::print4Guest(){
    if (user != nullptr)
    {
        cout << "Username: " << username << ", Location: " << location << ", Description: " << description << endl;
        cout << "Price: " << price << ", Minimum score: " << minScore << endl;
    }
}

void House::addRenter(Renter r)
{
    rentersRequested.push_back(r);
}

void House::printRenterRequested()
{
    cout << "List of requested people: " << endl;
    for (Renter &r : rentersRequested)
    {
        r.printRenterInfo();
    }
}

void House::acceptRenter(Renter *r)
{
    renter = r;
    usernameR = r->getUsername();

    rentersRequested.clear();
    rentersRequested.shrink_to_fit(); // reduces the vector’s capacity to fir the size
    // https://www.techiedelight.com/delete-vector-free-memory-cpp/#:~:text=Delete%20vector%20contents%20and%20free%20up%20memory%20in,the%20vector.%20...%204%204.%20Using%20vector%3A%3Aswap%20function
}

// get
User* House::getUser()
{
    return user;
}

string House::getUsername(){
    return username;
}

string House::getLocation()
{
    return location;
}

string House::getDescription(){
    return description;
}

float House::getPrice()
{
    return price;
}

int House::getMinScore()
{
    return minScore;
}

int House::getAvaivability()
{
    return avaivability;
}

string House::getUsernameR(){
    return usernameR;
}

Renter* House::getRenter()
{
    return renter;
}

vector<Renter> House::getRenterList()
{
    return rentersRequested;
}


