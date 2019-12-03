// 23 Nov 2019
/* ---------------Implicit conversions -----------
   Implicit conversions are automatically performed when a value is copied to a compatible type

*/

#include <iostream>
using namespace std;

int main()
{
    ///------ Conversion from a smaller type to larger type -----------------
    short a = 30;
    int b = a;        // short to int. promotion . No change in value
    double d = 34.65;
    float f = d;      // double to float. promotion. No change in value

    ///------ Conversion from a larger type to smaller type or a different type -----------------
    /// double to float, float to int, long to int, int to char

    int c = f;            // float to int. decimal value removed.  c = 34
    int neg = -1;
    unsigned int unInt = neg;
    cout << " b: " << b << " f: " << f << " c: " << c << " unInt: " << unInt << endl;

    // In all cases, converting a value into a type that doesn’t have a large enough range
    // to support the value will lead to unexpected results.
    // This should be avoided
    int i{ 30000 };
    char ch = i;
    cout << static_cast<int>(ch) << endl;  // char ch is converted back to integer

    // In this example, we’ve assigned a large integer to a char (that has range -128 to 127).
    // This causes the char to overflow, and produces an unexpected result 48.

    char ch2 = static_cast<char>(i);
    cout << ch2 << endl; // outputs 0

    char ch3 = static_cast<char>(87); // prints 'W'
    cout << ch3 << endl;

    ///-----------------------

    return 0;
}
