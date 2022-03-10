#include <iostream>
using namespace std;

class A
{
public:
    virtual void fun()
    {
        cout << " A::fun() ";
    }
};

class B : public A
{
public:
    void fun()
    {
        cout << " B::fun() ";
    }
};

int main()
{
    A *a = new B();
    a->fun();

    return 0;
}

/*

g++ -fdump-class-hierarchy vtable.cpp

Vtable for A
A::_ZTV1A: 3u entries
0     (int (*)(...))0
8     (int (*)(...))(& _ZTI1A)
16    (int (*)(...))A::fun

Class A
   size=8 align=8
   base size=8 base align=8
A (0x0x7f5d50776d80) 0 nearly-empty
    vptr=((& A::_ZTV1A) + 16u)

Vtable for B
B::_ZTV1B: 3u entries
0     (int (*)(...))0
8     (int (*)(...))(& _ZTI1B)
16    (int (*)(...))B::fun

Class B
   size=8 align=8
   base size=8 base align=8
B (0x0x7f5d505ce2d8) 0 nearly-empty
    vptr=((& B::_ZTV1B) + 16u)
  A (0x0x7f5d50776de0) 0 nearly-empty
      primary-for B (0x0x7f5d505ce2d8)


*/
