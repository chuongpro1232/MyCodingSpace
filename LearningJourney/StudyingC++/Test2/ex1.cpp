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
protected:
    string name;
    int year;

public:
    Vehicle(string nameVal = "", int yearVal = 0)
        : name(nameVal), year(yearVal) {}
    string getName()
    {
        return name;
    }
    int getYear()
    {
        return year;
    }
};

class Car : public Vehicle
{
private:
    int plateNumber;

public:
    Car(string nameVal = "", int yearVal = 0, int plateNumberVal = 0)
        : Vehicle(name, year), plateNumber(plateNumberVal) {}
    int get_plateNumber()
    {
        return plateNumber;
    }
    string getName()
    {
        return name;
    }
    int getYear()
    {
        return year;
    }
};

int main()
{

    Car *cars = new (std::nothrow) Car[3]{
        Car("Audi R8", 2019, 23456),
        Car("Mercedes 2018", 2018, 37801),
        Car("BMW 2019", 2019, 98123)};

    cout << "test" << cars[2].getYear();
    int oldest_car = cars[0].getYear();
    int car_name;
    for (int i = 0; i < 3; i++)
    {
        if (oldest_car > cars[i].getYear())
        {
            oldest_car = cars[i].getYear();
            car_name = i;
        }
    }
    cout << "The oldest car is " << cars[car_name].getName() << " that was manufacturing in " << cars[car_name].getYear() << " years, with the plate number is " << cars[car_name].get_plateNumber();
    return 0;
}