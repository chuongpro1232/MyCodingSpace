#include <iostream>
using namespace std;
template <class X, class Y>
void myFunc(x in1, y in2)
{
    cout << (in1 / in2) << endl;
}

int main()
{
    int int1 = 10;
    float float1 = 2.21;
    myFunc<int, float>(float1, int1);
    return 0;
};