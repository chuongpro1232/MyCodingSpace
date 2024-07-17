/*1.	Dynamic memory allocation for objects
Write a C++ program which defines a class named Book with two private attributes name (string) and price (integer). Provide constructor to initialize those attributes.
a)	Create three Book objects using dynamic memory allocation and initialize values for them through the constructor. You should check for NULL pointer to detect whether the allocations are succeeded or not.
Use range-based for loop to print out all information of the objects, and free up memory space after that.
b)	Ask the user to enter a number n. Create an array of n Book objects using dynamic memory allocation and ask the user to input value for them.
Print out the most expensive book. Free up memory space after that.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::string;

class Book
{
private:
    string name;
    int price;

public:
    Book(string nameVal = "", int priceVal = 0)
        : name(nameVal), price(priceVal) {}
    string toString()
    {
        return "Name = " + name + "\nPrice = " + std::to_string(price);
    }
    void setName(string nameVal)
    {
        name = nameVal;
    }
    void setPrice(int priceVal)
    {
        price = priceVal;
    }
    int getPrice()
    {
        return price;
    }
    string getName()
    {
        return name;
    }
};

int main()
{
    Book *book1 = new (std::nothrow) Book("sau`", 20);
    Book *book2 = new (std::nothrow) Book("tim", 30);
    if (book1 == nullptr || book2 == nullptr)
    {
        cout << "Fail to request dynamic memory allocation \n";
        return -1;
    }
    for (Book *book : {book1, book2})
    {
        cout << book->toString() << "\n";
        delete book;
    }
    // Question B
    int n;
    cout << "Input the number of books: ";
    cin >> n;
    Book *bookn = new (std::nothrow) Book[n];
    string name;
    int price, biggest_price = 0, expensive;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name for the book " << i + 1 << " : ";
        do
        {
            getline(cin, name);
        } while (name == "");
        bookn[i].setName(name);
        cout << " > Price: ";
        cin >> price;
        bookn[i].setPrice(price);
        if (biggest_price < bookn[i].getPrice())
        {
            biggest_price = bookn[i].getPrice();
            expensive = i;
        }
    }
    cout << "The most expensive book is: " << bookn[expensive].getName() << " with " << bookn[expensive].getPrice();

    delete[] bookn;
    return 0;
}