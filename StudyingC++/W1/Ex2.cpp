#include <iostream>
using namespace std;

int main()
{
    int array[5] = {};
    cout << "what is ur five numbers?";
    for (int i = 0; i < 5; i++)
    {

        cin >> array[i];
    }
    int total = 0;
    int max = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int z = 1; z < 5; z++)
        {
            if (array[i] < array[z])
            {
                max = array[z];
            }
        }
        // if (array[i] < array[i++])
        // {
        //     max = array[i++];
        // }
        total = total + array[i];
    }
    cout << "The biggest number is " << max << "\n";
    cout << "The total is " << total;
    return 0;
}