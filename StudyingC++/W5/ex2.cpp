
// /*2.	Dynamic memory allocation for class attribute
// Duplicate and modify the program of question 1 so that name attribute is a pointer, which is dynamically allocated in heap memory
//  via the class constructor. Write a destructor to free up memory allocated for it (when a Book object is destroyed).
// */

// #include <iostream>
// using std::cin;
// using std::cout;
// using std::string;

// class Book
// {
// private:
//     string *name;
//     int *price;

// public:
//     Book(string nameVal = "", int priceVal = 0)
//     {
//         name = new (std::nothrow) string;
//         *name = (name == NULL) ? throw(101) : nameVal;
//         price = new (std::nothrow) int;
//     }

//     string toString()
//     {
//         return "Name = " + name + "\nPrice = " + std::to_string(price);
//     }
//     void setName(string nameVal)
//     {
//         name = nameVal;
//     }
//     void setPrice(int priceVal)
//     {
//         price = priceVal;
//     }
//     int getPrice()
//     {
//         return price;
//     }
//     string getName()
//     {
//         return name;
//     }
// };

// int main()
// {
//     Book *book1 = new (std::nothrow) Book("sau`", 20);
//     Book *book2 = new (std::nothrow) Book("tim", 30);
//     if (book1 == nullptr || book2 == nullptr)
//     {
//         cout << "Fail to request dynamic memory allocation \n";
//         return -1;
//     }
//     for (Book *book : {book1, book2})
//     {
//         cout << book->toString() << "\n";
//         delete book;
//     }
//     // Question B
//     int n;
//     cout << "Input the number of books: ";
//     cin >> n;
//     Book *bookn = new (std::nothrow) Book[n];
//     string name;
//     int price, biggest_price = 0, expensive;
//     for (int i = 0; i < n; i++)
//     {
//         cout << "Enter the name for the book " << i + 1 << " : ";
//         do
//         {
//             getline(cin, name);
//         } while (name == "");
//         bookn[i].setName(name);
//         cout << " > Price: ";
//         cin >> price;
//         bookn[i].setPrice(price);
//         if (biggest_price < bookn[i].getPrice())
//         {
//             biggest_price = bookn[i].getPrice();
//             expensive = i;
//         }
//     }
//     cout << "The most expensive book is: " << bookn[expensive].getName() << " with " << bookn[expensive].getPrice();

//     delete[] bookn;
//     return 0;
// }