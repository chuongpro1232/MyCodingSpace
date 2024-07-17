/* Same as question 2, but use dynamic allocation for name attribute
   New changes are noted with UPDATE comments */

#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::string;

class Book
{
private:
    string *name; // UPDATE
    int price;

public:
    // constructor UPDATE
    Book(string nameVal = "", int priceVal = 0)
    {
        name = new (std::nothrow) string(nameVal);
        price = priceVal;
    }

    // function to return info as a string
    string toString()
    {
        std::stringstream sstr;
        sstr << "name: " << ((name == nullptr) ? "N/A" : *name)
             << ", price: " << price;
        return sstr.str(); // get and return string content from the stringstream
    }

    // Extra get and set functions to access private attributes
    void setName(string nameVal) { *name = nameVal; } // UPDATE
    void setPrice(int priceVal) { price = priceVal; }

    int getPrice() { return price; }

    // destructor UPDATE
    ~Book()
    {
        delete name;
    }
};

int main()
{
    // Qa
    // request dynamic memory allocation
    Book *book1 = new (std::nothrow) Book("Harry Potter", 100);
    Book *book2 = new (std::nothrow) Book("Doremon", 200);
    Book *book3 = new (std::nothrow) Book("Dragon Balls", 300);

    if (book1 == nullptr || book2 == nullptr || book3 == nullptr)
    {
        cout << "Fail to request memory allocation for book objects \n";
        return -1;
    }

    // print out info using range based for loop
    for (Book *book : {book1, book2, book3})
    { // book will be book1, book, book3
        cout << book->toString() << "\n";
        delete book; // free up allocated memory of book1, book2, book3
    }

    // delete book1; //free up allocated memory
    // delete book2; //free up allocated memory
    // delete book3; //free up allocated memory
    // Book *book4 = new (std::nothrow) Book("X MEN", 300); //will get same addr freed from book1
