/*4.	Define a class namely Cat with public attributes are name (string), age (int).
Define another class namely Person with public attributes are cat (Cat class) and name (string).
Each class must have their own constructors.
a.	Make an array of three persons, and initialize values for them.
b.	Print out the information of the person who has the cat with the highest age (also print out information of that cat).
*/

#include <iostream>
using std::cin;
using std::cout;
using std::string;

class Cat
{
public:
    string name;
    int age;

    Cat(string nameVal = "", int ageVal = 0)
        : name(nameVal), age(ageVal) {}
};

class Person
{
public:
    Cat cat;
    string name;
    Person(string nameVal = "", Cat catVal = Cat())
        : name(nameVal), cat(catVal) {}
};

int main()
{
    int max_age, highest = 0;
    ;
    Person perray[3] = {Person("Thanh Tu", Cat("ni", 4)),
                        Person("Hoang Quy", Cat("Chu", 5)),
                        Person("Ngoc Duy", Cat("Giaow", 3))};
    for (int i = 0; i < 3; i++)
    {
        cout
            << "name of person " << i + 1 << " " << perray[i].name
            << " and their cat is " << perray[i].cat.name << " "
            << perray[i].cat.age << std::endl;
        if (perray[i].cat.age > highest)
        {
            highest = perray[i].cat.age;
            max_age = i;
        }
    }
    cout << "the Cat with the highest age is: " << perray[max_age].cat.name
         << " with " << perray[max_age].cat.age << " years old "
         << "and belong to " << perray[max_age].name;
}