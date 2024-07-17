#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "please input your number(a,b): ";
    cin >> a >> b;
    float number = (0.0 - b) / a;
    cout << "the result is " << number;
    return 0;
}