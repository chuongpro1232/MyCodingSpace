#include <iostream>
using namespace std;

class Juice
{
private:
    string name;
    int price;

public:
    Juice(){};
    Juice(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
    void show()
    {
        cout << "Juice: " << name
             << "\nprice: " << price << endl;
    }
    // a/

    Juice operator--()
    {
        this->price--;
        return *this;
    }

    // b/
    friend Juice TotalPrice(Juice obj1, Juice obj2);
    // c/
    friend Juice Reduce(int n, Juice obj1);
};

Juice TotalPrice(Juice obj1, Juice obj2)
{
    Juice tmp;
    if (obj1.name == obj2.name)
    {
        tmp.name = obj1.name;
        tmp.price = obj1.price + obj2.price;
        return tmp;
    }
    else
    {
        tmp.name = "NA";
        tmp.price = 0;
        return tmp;
        cerr << "Not the same juice" << endl;
    }
}

Juice Reduce(int n, Juice obj1)
{
    Juice tmp;
    tmp.name = obj1.name;
    tmp.price = obj1.price * (100 - n) / 100;
    return tmp;
}

int main()
{
    Juice obj1("Apple", 20), obj2("Apple", 10), obj3;
    // obj1.show();
    obj3 = TotalPrice(obj1, obj2);
    // obj3 = Reduce(50, obj1);
    obj3.show();
    // Question B
    Juice juiArr[4] = {Juice("Organe Juice", 200), Juice("Lemonade", 150), Juice("Coconut water", 200), Juice("Ca phe sua da", 250)};
    cout << "\nAll drink in the array: \n";
    for (int i = 0; i < 4; i++)
    {
        juiArr[i].show();
    }
    return 0;
}