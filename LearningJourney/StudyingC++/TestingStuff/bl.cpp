#include <iostream>
using std::cin;
using std::cout;

void funct(int *&pt, int *newAddr)
{
    pt = newAddr;
}

int main()
{
    int a = 10, b = 20;
    int *pt = &a;
    funct(pt, &b);
    cout << *pt;
    return 0;
}