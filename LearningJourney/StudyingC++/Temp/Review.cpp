/* Source file:
 *  Definitions of functions/ methods for the module
 */

#include <iostream>
#include "Review.h"
#include "Renter.h"
#include "House.h"

using namespace std;

void Review::addReviewRenter2House(Renter *r, House *h, int score, string comment){
    this->renter = r;
    this->house = nullptr;

    this->renterC = nullptr;
    this->houseC = h;

    this->score = score;
    this->comment = comment;
}

void Review::addReviewHouse2Renter(House *h, Renter *r, int score, string comment){

    this->renter = nullptr;
    this->house = h;

    this->renterC = r;
    this->houseC = nullptr;

    this->score = score;
    this->comment = comment;
}

void Review::print(){
    if(renterC != nullptr){
        cout << "Renter that leave comment: " << renterC->getUsername() << endl;    
        cout << "House that being commented: " << house->getUsername() << endl;
        cout << "Score: " << score << ", Comment: " << comment << endl;
    }
    else if(houseC != nullptr){
        cout << "House owner that leave comment: " << houseC->getUsername() << endl;    
        cout << "Renter that being commented: " << renter->getUsername() << endl;
        cout << "Score: " << score << ", Comment: " << comment << endl;
    }
}

