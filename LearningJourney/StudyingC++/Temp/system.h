#if 0 //members in our group could not agree on 1 style of coding, each code in a different way. So we have trouble in combine our code, this lead to some part like this file neglected
#ifndef __SYSTEM_H__ 
#define __SYSTEM_H__ 
/* make sure that this file will be included only once in compilation process
   (when the keyword __USER_H__ is not defined before)
*/
#include <iostream>
using namespace std;
class House;
class Date;

class System  {
private:
     vector <House> houses {};

public:
    System(){} //constructor 

bool addHouse();

bool saveAllhouses();

bool reloadHouseData();

void showAllHouses();

int findHouse(string location);

void searchHouse(string location);


    
    
};

#endif

#endif