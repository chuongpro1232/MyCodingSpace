#include <iostream>
using std::cin;
using std::cout;

#include "calculator.h"
int main()
{

    cout << "REC CALCULATION";
    cout << "Input";
    int length = 0, width = 0;
    cin >> length >> width;
    cout << "Perimeter: %d\n", calPerimeter(length, width);
    cout << "Area: %d\n", calArea(length, width);

    return 0;
}