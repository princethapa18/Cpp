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

class Base
{
public:
    void fun() { cout << "Base fun" << endl ; }
};

class Derived : public Base
{
public:
    void fun()  { cout << "Derived fun"  << endl ; }
    void fun1() { cout << "Derived fun1" << endl ; }
};

int main()
{
    Base *bptr = new Base;
    /// DOWNCASTING  ptr to Base to ptr to Derived
    /// Derived *dp = bptr; /// When DOWNCASTING implicit conversion not allowed . Gives compile error

    Derived *dptr = static_cast<Derived*>(bptr); // it allows this conversion. Downcast
    dptr->fun();  /// calls fun()  of the Derived class. prints ---> Derived fun
    dptr->fun1(); /// calls fun1() of the Derived class. prints ---> Derived fun1

    Derived d1;
    Base* b1 = (Base*)(&d1); // allowed
    Base* b2 = static_cast<Base*>(&d1);

    /// UPCASTING  ptr to Derived to ptr to Base
    Derived *dptr2 = new Derived;
    Base *bptr1 = dptr2;  /// when UPCASTING implicit conversion allowed

    Base *bptr2 = static_cast<Base*>(dptr2);  /// this is allowed
    bptr2->fun(); // prints Base fun

    /// When UPCASTING is done there is object slicing


    return 0;
}

