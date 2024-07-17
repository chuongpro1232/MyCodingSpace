
#if 0 //members in our group could not agree on 1 style of coding, each code in a different way. So we have trouble in combine our code, this lead to some part like this file neglected
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#define HFILENAME "houseFile.dat" //create file name for house
#include "system.h"
#include "House.h"
#include "Date.h"



using namespace std;

   //constructor 

int System :: findHouse ( string location) { //base on location

for (int i = 0; i < houses.size(); i++){
     int res = houses[i].location.compare(location);
    if (res != 0) {
     return -1; }
 } 
 return 1;
}

bool System :: addHouse () {
    
    cout << "House's location: ";
    string location;
    do {
        getline(cin, location );
    } while (location == "");

    cout << "House's description: ";
    string description;
    do {
        getline(cin, description );
    } while (description == "");

    float price;
    cout << "House's price: ";
    cin >> price;
   
    int minScore;
    cout << "Minimum creditpoint for renter to rent: ";
    cin >> minScore;
    
    int avaivability = 1;

    int day, month, year;
    int daye, monthe, yeare;
cout<<"set start date: \n";
cout <<"day: "; cin >> day;
cout <<"month: "; cin >> month;
cout <<"year: "; cin >> year;
cout<<"\n";
cout<<"set end date: \n";
cout <<"day: "; cin >> daye;
cout <<"month: "; cin >> monthe;
cout <<"year: "; cin >> yeare;

Date st(day, month, year);
Date en(daye, monthe, yeare);

string start, end;
start = st.toString();
end = en.toString();

    houses.push_back( House(start, end, location, price, minScore,avaivability, description) );
    cout << "House has been listed successfully! \n";
    return true;
} 

bool System :: saveAllhouses () {
    std::ofstream houseFile;
    houseFile.open(HFILENAME, std::ios::out); //remember to use ::app to append
        if (!houseFile.is_open()) {
            cout << "Fail to create/open file \n";
            return false;
        }
    //Store in the file
    for (House &hou: houses) { //remember to save data in the right order
        houseFile << hou.start << ":" << hou.end << ":" << hou.location << ":" << hou.price << ":" <<hou.minScore <<":" << hou.avaivability << ":" << hou.description << "\n";
        }
        return true;
    }

bool System :: reloadHouseData(){
    
        std::ifstream houseFile;
        houseFile.open(HFILENAME, std::ios::in);
     
        if (!houseFile.is_open()) {
            cout << "(There is no user in this app yet) \n";
            return false;
        }
        /* Reload data from the file */
        string start, end, location, price, minScore,avaivability, description; 

        while (!houseFile.eof()) { //use .eof instead of that == "" way in w6
          
            //Read data from file
            getline(houseFile, start, ':'); //remember to put ':' at the end of every getline
            getline(houseFile, end, ':');
            getline(houseFile, location, ':'); 
          //read name until seeing ':' character
            getline(houseFile, price, ':');
            getline(houseFile, minScore, ':');
            getline(houseFile, avaivability, ':');
            getline(houseFile, description, '\n'); 
          //read name until seeing ':' character
 if (start == "" || end == "") {break;}
            //Store into the house list
            houses.push_back( House(start, end, location,stof(price),stoi(minScore),stoi(avaivability),description ) );  

        }

        return true;
    }


void System :: showAllHouses(){
    cout << "\nAll houses in the app: \n";
    for (House &hou: houses){ 
        cout << hou.start << " : " << hou.end << " : " << hou.location << " : " << hou.price << " : " << hou.minScore <<" : "<< hou.avaivability <<" : " << hou.description << "\n";
        }
    }

void System :: searchHouse(string locational) {
    short flag = 0;
    for (int i = 0; i < houses.size(); i++){
     int res = houses[i].location.compare(locational);
    if (res == 0) //put && user.credit == minScore here
    { 
     cout <<"\nLocation: "<<houses[i].location<<", price: "<<houses[i].price<< "\nPeriod: from "<<houses[i].start<<" to "<< houses[i].end<<"\nDescription:"<<houses[i].description;
     flag = 1;
     }
    if (!flag) {cout<<"invalid location";}
 } 
}


#endif

    

