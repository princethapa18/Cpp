/* 12 Dec 2019
   ************ Virtual Functions (late binding) ******************************
   
   ------ VTable  ( Virtual Table ) ------------------------------
   Virtual Table is a lookup table of function pointers used to dynamically bind the virtual functions to objects at runtime.
   It is not intended to be used directly by the program, and as such there is no standardized way to access it.

   Every class that uses virtual functions (or is derived from a class that uses virtual functions)
   is given it's own virtual table as a secret data member.
   This table is SET UP by the COMPILER at COMPILE TIME.

   A virtual table contains ONE ENTRY AS A FUNCTION POINTER FOR EACH VIRTUAL FUNCTION
   that can be called by objects of the class.
   Virtual table stores NULL POINTER TO PURE VIRTUAL FUNCTIONS.
   Virtual Table is created even for classes that HAVE VIRTUAL BASE CLASSES.
   In this case, the vtable has pointer to the shared instance of the base class along with
   the pointers to the classe's virtual functions if any.

   VTable is not a class member

   ------ vtable pointer  ( __vptr ) ------------------------------

   This vtable pointer or _vptr, is a hidden pointer added by the Compiler to the base class.
   And this pointer is pointing to the virtual table of that particular class.
   This _vptr is inherited to all the derived classes.
   Each object of a class with virtual functions transparently stores this _vptr.
   Call to a virtual function by an object is resolved by following this hidden _vptr.

   __vptr is a member pointer and it's pointed to the appropriate VTable at run time (upon object initialization)

   Calling a virtual function is slower than calling a non-virtual function
   1. We have to use the *__vptr to get the appropriate virtual table.
   2. We have to index the virtual table to find the correct(most derived) function to call.

   Any class that uses virtual functions has a __vptr, and
   thus each object of that class will be bigger by 1 pointer.

   Virtual functions are powerful but they do have a performance cost.

*/

#include <iostream>
using namespace std;
class B {
public:
    virtual void fun1() { cout << "B::fun1()" << endl; }
    virtual void fun2() { cout << "B::fun2()" << endl; }
    void fun3() { cout << "B::fun3()" << endl; }
};

/*
     *__vptr  --->   | B's VTable |
                     |  fun1()    |
                     |  fun2()    |
*/

class D1 : public B {
public:
    void fun1() { cout << "D1::fun1()" << endl; }
    virtual void fun3() { cout << "D1::fun3()" << endl; }
};

/*
     *__vptr  --->   | D1's VTable |
                     |  fun1()     |  ---->   D1's fun1()
                     |  fun2()     |  ---->   B's  fun2()
                     |  fun3()     |  ---->   D1's fun3()
*/

class D2 : public D1 {
public:
    void fun2() { cout << "D2::fun2()" << endl; }
    void fun3() { cout << "D2::fun3()" << endl; }
};

/*
     *__vptr  --->   | D2's VTable |
                     |  fun1()     |  ---->   D1's fun1()
                     |  fun2()     |  ---->   D2's fun2()
                     |  fun3()     |  ---->   D2's fun3()
*/

int main()
{
    /*
    D2 *d2ptr = new D2;
    D1 *d1ptr = d2ptr;

    d1ptr->fun2(); //  D2's VTable  ---> D2::fun2()
    d1ptr->fun1(); //  D2's VTable  ---> D1::fun1()
    d1ptr->fun3(); //  D2's VTable  ---> D1::fun3()
    */

    D1 d1;
    B *bptr = &d1;
    bptr->fun1();   // D1's VTable ---> D1::fun1()
    bptr->fun2();   // D1's VTable ---> B::fun2()
    bptr->fun3();   // B::fun3()     Because fun3() in Base B is non-virtual

    cout << "-------------" << endl;

    D1 *d1ptr1 = new D1;
    d1ptr1->fun3(); // D1::fun3()
    bptr = d1ptr1;
    bptr->fun3(); // B::fun3()  Because fun3() in Base B is non-virtual

    cout << "-------------" << endl;
    D2 *d2ptr1 = new D2;
    bptr = d2ptr1;
    bptr->fun3(); // B::fun3() Because fun3() in Base B is non-virtual

    d1ptr1 = d2ptr1;
    d1ptr1->fun3(); // Because fun3() is virtual in D1 and D2 is derived from D1
                    // and D2 also has fun3().
                    // Therefore *__vptr is set to D2's VTable
                    // fun3() is from D2::fun3()


    return 0;
}
