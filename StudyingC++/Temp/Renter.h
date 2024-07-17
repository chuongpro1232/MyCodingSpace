#ifndef __RENTER_H__
#define __RENTER_H__
/* make sure that this file will be included only once in compilation process
   (when the keyword __RENTER_H__ is not defined before)
*/

#include <iostream>
#include <vector>

#include "User.h"
#include "House.h"

using namespace std;

// class House;
// class User;

class Renter
{
private:
    User *user; //associate with user

    House *houseRequest; //associate to the requested house
    
    House *occupy; //associate to the occupy house

public:
    // constructor
    
    // Renter(User *userVal = nullptr, House *houseRequestVal = nullptr);

    // Renter(User *userVal = nullptr , House *houseRequestVal = nullptr) : user(userVal), houseRequest(houseRequestVal) {}
    
    Renter(){
        this->user = nullptr;
        this->houseRequest = nullptr;
        this->occupy = nullptr;
    };

    // Renter(User *userVal , House *houseRequestVal, House *occupyVal ){
    //     user = userVal;
    //     houseRequest = houseRequestVal;
    //     occupy = occupyVal;
    // }

    string getUsername();

    House* getOccupy(); 

    void printRenterInfo();

    void print();

    void requestHouse(User *u, House *h);

    void acceptOccupy(House *h);

    void freeRequest();
        
    
};
#endif