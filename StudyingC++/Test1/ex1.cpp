/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2022-3
  Lab Assessment: 1
  Author: Tran Thanh Tu
  ID: S3957386
  Compiler used: 8.1.0
  Created  date: 26/11/2022
  Acknowledgement: List the resources that you use to complete this assessment (write 'None' if you don't use any).
*/

#include <iostream>
#include <fstream>
#define CREATING 1
#define READING 2
#define CHECKING 3
using std::cin;
using std::cout;
using std::string;

class Items
{
public:
    int price;
    string name;

    Items(string nameVal = "", int priceVal = 0)
        : name(nameVal), price(priceVal) {}
};
int checkCMD(char str[])
{

    if (str[1] == 'w')
    {
        return CREATING;
    }

    if (str[1] == 'r')
    {
        return READING;
    }

    return CHECKING;
}

int main(int argc, char *argv[])
{

    int MAX_SIZE;
    int cmd = checkCMD(argv[1]);
    std::fstream sellingfile;
    if (cmd == CREATING)
    {
        cout << "what is the total number of selling items";
        cin >> MAX_SIZE;
        Items itarr[MAX_SIZE];
        sellingfile.open("sellingItems.dat", std::ios::out);
        if (!sellingfile)
        {
            std::cerr << "Can't open/create the file";
            return -1;
        }
        for (int i = 0; i < MAX_SIZE; i++)
        {

            cout << "The name of No " << i + 1 << " items is: ";
            cin >> itarr[i].name;
            sellingfile << itarr[i].name << " : ";
            cout << "The price of No " << i + 1 << " items is: ";
            cin >> itarr[i].price;
            cin.ignore();
            sellingfile << itarr[i].price << std::endl;
        }
        cout << "Your information has been saved to the file" << std::endl;
        sellingfile.close();
    }
    if (cmd == READING)
    {
        int num;
        string info;
        sellingfile.open("sellingItems.dat", std::ios::in);
        if (!sellingfile)
        {
            std::cerr << "Can't open/create the file";
            return -1;
        }

        std::getline(sellingfile, info);
        cout << info;
    }
    // if (cmd == CHECKING)
    // {
    //     char info[100];
    //     int number;
    //     sellingfile.open("sellingItems.dat", std::ios::in);
    //     if (!sellingfile)
    //     {
    //         std::cerr << "Can't open/create the file";
    //         return -1;
    //     }
    //     for (int i = 0; i != '\0'; i++)
    //     {
    //         std::getline(sellingfile, info);
    //     }

    //     cout << info;
    // }
    return 0;
}