#ifndef __HOUSE_H__
#define __HOUSE_H__
/* make sure that this file will be included only once in compilation process
   (when the keyword __HOUSE_H__ is not defined before)
*/

#include <iostream>
#include <vector>

// #include "User.h"
// #include "Renter.h"

using namespace std;

class User;
class Renter;

class House
{
private:
    User *user; // associate with user

    string username; // to knows the house belong to user

    string location;
    string description;
    float price;
    int minScore;
    int avaivability; // 0=FALSE 1=TRUE

    string usernameR; //to knows the user that rent the house
    Renter *renter;

    vector<Renter> rentersRequested;

public:
    // House(User *userVal = nullptr, string locationVal = "", float priceVal = 0, int minScoreVal = 0,
    // bool avaivabilityVal = true, Renter *renterVal = nullptr);

    // put the default constructor hear because of mutiple defenition error

    House();
    
    House(User *userVal, string locationVal, string descriptionVal, float priceVal, int minScoreVal, int avaivabilityVal);
    
    void putHouse(User *logIn);

    void print();

    void print4Guest();

    void addRenter(Renter r);

    void printRenterRequested();

    void acceptRenter(Renter *r);

    // get 
    
    User* getUser();

    string getUsername();
    
    string getLocation();

    string getDescription();

    float getPrice();

    int getMinScore();

    int getAvaivability();

    string getUsernameR();

    Renter *getRenter();

    vector<Renter> getRenterList();


  
};

#endif