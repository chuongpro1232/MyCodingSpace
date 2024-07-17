#include <iostream>
#include <cstring>
using std::cin;
using std::cout;

int main()
{
    char string[100];
    cout << "what is your sentence?";
    cin.getline(string, sizeof(string));
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = (isupper(string[i])) ? tolower(string[i]) : toupper(string[i]);
    }

    cout << string;
    return 0;
}