/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2022-3
  Lab Assessment: 2
  Author: Tran Thanh Tu
  ID: S3957386
  Compiler used: 8.1.0
  Created  date: 24/12/2022
  Acknowledgement: List the resources that you use to complete this assessment (write 'None' if you don't use any).
*/
#include <iostream>
using std::cin;
using std::cout;
using std::string;

class Vehicle
{
public:
    string name;
    int year;

public:
    Vehicle(string nameVal = "", int yearVal = 0)
        : name(nameVal), year(yearVal) {}
};

class Car : public Vehicle
{
public:
    int plateNum;

public:
    Car(string name = "", int year = 0, int plateNumVal = 0)
        : Vehicle(name, year), plateNum(plateNumVal) {}

    int getYear() { return year; }
};

int main()
{

    Car *cars = new (std::nothrow) Car[3]{
        Car("Audi R8", 2019, 23456),
        Car("Mercedes 2018", 2018, 37801),
        Car("BMW 2019", 2019, 98123)};

    Car *oldest = &cars[0];
    for (int i = 1; i < 3; i++)
    {
        if (oldest->getYear() > cars[i].getYear())
        {
            oldest = &cars[i];
        }
    };
    cout << "> The oldest car is " << oldest->name << " that was manufacturing in " << oldest->year << " years, with the plate number is " << oldest->plateNum;

    delete[] cars;
    return 0;
}
