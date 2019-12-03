/// 26 Nov 2019  static_cast < new_type > ( expression )
/* compile time cast --->   type checking done at compile time
   implicit/explicit conversion

   static_cast can perform conversions between pointers to related classes,
   not only upcasts (from pointer-to-derived to pointer-to-base),
   but also downcasts (from pointer-to-base to pointer-to-derived).
   No checks are performed during runtime to guarantee that the object
   being converted is in fact a full object of the destination type

*/
#include <iostream>
using namespace std;

int main()
{
    float f = 3.5;
    int a = f;                   /// C-Style Cast
    int b = static_cast<int>(f);
    cout << b << endl;
    double d = 4.6;
    int x = (int)d;
    char c = 'a';
    x = c;
    cout << x << endl;
    char c1[2] = {'h', 'e'};
    //x = c1;                   /// error: invalid conversion frm char* to int
    //x = static_cast<int>(c1); /// error: invalid static_cast from type char[2] to type int

    ///-----------------------
    int a1 = 10;
    char ch = 'a';
    int* ptr1 = (int*)&ch; ///  this is wrong cast but C-style cast allows it to pass at compile time. But may fail at run time
    //int* ptr2 = static_cast<int*>(&ch); /// error: invalid static_cast from type char* to type int*

    /// converting a pointer to int to a pointer to char
    char* chrPtr = (char*)ptr1;  /// this is allowed to compile. Here C-style cast behaves like a reinterpret_cast
    char *chrPtr3 = reinterpret_cast<char*>(ptr1); /// reinterpret_cast allows this conversion between pointers of diff types.
                                                   /// reinterpret_cast is dangerous
    ///char* chrPtr1 = static_cast<char*>(ptr1);  /// static_cast doesn't allow this gives error

    cout << *chrPtr3 << endl;
    ///-------------------------------------------------



    return 0;
}
