/*Write a C++ program which take a number as an argument from the command line, which is one of
following data type:
• an integer number (e.g. 12)
• a floating-point number (e.g. 3.14)
• a hexadecimal number which must be preceded by "0x" (e.g. 0x19, 0xAC).
a) Write a function named doubleVal() with multiple overloaded versions that accept an
integer, a floating-point number or a string represented a hexadecimal number, and return
a doubled value (with integer/ double data type).
b) Use that function inside main() to print out the doubled value. Format the I/O stream so that
the precision is two digits after the decimal point for floating point value, and it prints outs in
hexadecimal format (with 0x prefix) for hexadecimal value
Note: Assume that the user always enters valid data with positive value only.
Hint: You may need to use stringstream with I/O formatting to convert from any numerical string to
integer/ double.*/

#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
using std::cout;

// define Constants for different formats of input string
#define INT_TYPE 0
#define FLOAT_TYPE 1
#define HEXA_TYPE 2

// 1st version with int input
int doubleVal(int num)
{
    return num * 2;
}

// 2nd version with floating point input
double doubleVal(double num)
{
    return num * 2;
}

// 3rd version with input is string (represented hexa number)  "0XAB" --> 342
int doubleVal(char hexaStr[])
{
    int val;

    std::stringstream sstr;
    sstr << std::hex
         << hexaStr; // input the string inside the stringstream (with hex format)
    sstr >> val;     // extract value from the stringstream (with int format)

    return val * 2;
}

// Check the format of number represented in the string
int checkType(char str[])
{
    // Check hexas
    if (str[0] == '0' && tolower(str[1]) == 'x')
    {
        return HEXA_TYPE;
    }

    // Check floating type
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '.')
        {
            return FLOAT_TYPE;
        }
    }

    return INT_TYPE; // int by default
}

int main(int argc, char *argv[])
{
    int type = checkType(
        argv[1]); // check format of input string (got from commandline argument)

    if (type == HEXA_TYPE)
    { // hexa
        cout << std::showbase << std::hex << doubleVal(argv[1]);
    }
    else if (type == FLOAT_TYPE)
    { // floating point
        cout << std::fixed << std::setprecision(2) << doubleVal(std::stod(argv[1]));
    }
    else
    { // integer
        cout << doubleVal(std::stoi(argv[1]));
    }

    return 0;
}