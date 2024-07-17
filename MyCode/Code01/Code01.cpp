#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;
int main()
{
    cout << "Nhan phim Enter de bat dau...";
    cin.ignore();
     cout << "\nDang load 0%....";
     Sleep(100);
     cout << "\nDang load 10%...";
     Sleep(100);
      cout << "\nDang load 20%...";
       Sleep(100);
       cout << "\nDang load 30%...";
        Sleep(100);
		cout << "\nDang load 40%...";
        Sleep(100);
		cout << "\nDang load 50%...";
        Sleep(100);
		cout << "\nDang load 60%...";
        Sleep(100);
		cout << "\nDang load 70%...";
        Sleep(100);
		cout << "\nDang load 80%...";
        Sleep(100);
		cout << "\nDang load 90%...";
        Sleep(100);
		cout << "\nDang load 100%...";
        Sleep(100);
  cout << "\nDa load xong!!!";
    Sleep(200);
   
    fstream newfile;
    newfile.open("input.txt", ios::in);
    if (newfile.is_open())
    {
        string tp;
        while (getline(newfile, tp))
        {
            cout << tp << endl;
            Sleep(100);
        }
        newfile.close();
    }
  system("pause");
    return 0;
}
