#ifndef __REVIEW_H__
#define __REVIEW_H__
/* make sure that this file will be included only once in compilation process
   (when the keyword __REVIEW_H__ is not defined before)
*/

#include <iostream>
#include "Renter.h"
#include "House.h"

using namespace std;

class Review{
private:
    Renter *renter;
    House *house;

// user that leave comment
    Renter *renterC;
    House *houseC;

    int score;
    string comment;

public:
    // constructor
    Review(){
        this->renter = nullptr;
        this->house = nullptr;

        this->renterC = nullptr;
        this->houseC = nullptr;

        this->score = 0;
        this->comment = "";
    };

    Review(Renter *renter, House *house, Renter *renterC, House *houseC, int score, string comment){
        this->renter = renter;
        this->house = house;

        this->renterC = renterC;
        this->houseC = houseC;

        this->score = score;
        this->comment = comment;
    };

    void addReviewRenter2House(Renter *r, House *h, int score, string comment);
    void addReviewHouse2Renter(House *h, Renter *r, int score, string comment);

    void print();
};

#endif