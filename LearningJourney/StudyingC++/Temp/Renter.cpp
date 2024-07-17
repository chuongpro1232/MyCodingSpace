/* Source file:  
*  Definitions of functions/ methods for the module
*/


#include <iostream>
#include <vector>

#include "User.h"
#include "Renter.h"
#include "House.h"

using namespace std;

// Definition

// Constructor

// Renter::Renter(User *userVal , House *houseRequestVal ) : user(userVal), houseRequest(houseRequestVal) {}

//Method

string Renter:: getUsername(){
    return user->getUsername();
}

House* Renter::getOccupy(){
    return occupy;
}

void Renter:: printRenterInfo(){
    cout << "Renter info: ";
    user->print();
}

void Renter::print() {
    cout << "Renter info: ";
    user->print();
    cout << "House info: ";
    houseRequest->print();
}

void Renter::requestHouse(User *u, House *h){
    user = u;
    houseRequest = h;
    occupy = nullptr;
}

void Renter::acceptOccupy(House *h){
    occupy = h;
}

void Renter::freeRequest(){
    houseRequest = nullptr;
}