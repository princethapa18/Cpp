// 30 Mar 2019
// Qns asked in HCL interview (30 Mar 2019)

#include <iostream>
using namespace std;
/*
    Empty Class/Struct -> which doesnt have any data members
    But it can have member functions
    Class/Struct is a type just like int, char, float etc.
    Class Empty {

    };
    Empty obj;   // if sizeof(Empty) is 0 byte then where will be the obj stored?
    Empty *obj = new Empty();

    Therefore the sizeof(Empty) class is 1 byte.

    Empty Class with virtual function
    class Empty
    {
        virtual void display();

    }

    Whenever a class has virtual function , the compiler creates a  hidden data member i.e virtual pointer (VPTR)
    which is the pointer to virtual table (VTABLE)
    Now the size will be 4 byte or 8 byte (depending on the platform 32 bit or 64 bit )

    EBCO - Empty Base Class Optimization
    Empty Member Optimization

    class E { };
    E arr[10];   // sizeof(arr) can't be zero

*/

class EmptyClass
{

};

class EmptyClassWithStaticVariable
{
    static int a;
};

typedef struct EmptyStruct
{

} EmptyStruct;

typedef struct EmptyStructWithStaticVariable
{
    static int a;
} EmptyStructWithStaticVariable;

class NonEmptyClass
{
    double  x;
    //int   d;
    char  c;
    //static int a;
    //static double b;
};

class EmptyClassWithFun
{
public:
    void display() {}
    int abc(int x) {return x*2;}
};

class EmptyClassWithVirtualFun
{
public:
    virtual void display() {}
    int abc(int x) {return x*2;}
};

class E1 {};
class E2 {};

// **** before EBCO ****

class Foo {
  E1 e1;
  E2 e2;
  //int data;
};

int fun()
{
    return 1;
}

int (*funptr)()= fun;

void fun2() {}
void (*funptr2)() = fun2;

int main()
{
    cout << "sizeof(void*) " << sizeof(void*) << endl;
    cout << "sizeof(char*) " << sizeof(char*) << endl;
    cout << "sizeof(int*) " << sizeof(int*) << endl;
    cout << "sizeof(double*) " << sizeof(double*) << endl;
    cout << "sizeof(char) " << sizeof(char) << endl;
    cout << "sizeof(double) " <<  sizeof(double) << endl;
    cout << "sizeof(int) " << sizeof(int) << endl;
    cout << "sizeof(float) " << sizeof(float) << endl;

    cout << "sizeof(EmptyClass) : " << sizeof(EmptyClass) << endl; // output:  1 why?
    cout << "sizeof(EmptyClassWithStaticVariable) : " << sizeof(EmptyClassWithStaticVariable) << endl; // output : 1

    cout << "sizeof(EmptyStruct) : " << sizeof(EmptyStruct) << endl;  // output : 1
    cout << "sizeof(EmptyStructWithStaticVariable) : " << sizeof(EmptyStructWithStaticVariable) << endl;  // output : 1

    cout << "sizeof(NonEmptyClass) : " << sizeof(NonEmptyClass) << endl;  // output : double 8  + char 1 = should be 9 but it gives 16

    cout << "sizeof(EmptyClassWithFun) : " << sizeof(EmptyClassWithFun) << endl; // output 1
    cout << "sizeof(EmptyClassWithVirtualFun) : " << sizeof(EmptyClassWithVirtualFun) << endl; // output 4  // VPTR

    cout << "sizeof(Foo) : " << sizeof(Foo) << endl;
    cout << "sizeof(funptr) : " << sizeof(funptr) << endl;
    cout << "sizeof(funptr2) : " << sizeof(funptr2) << endl;

    return 0;
}
