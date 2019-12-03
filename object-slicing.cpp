// 28 june 2018
/* 
Object Slicing in C++

In C++, a derived class object can be assigned to a base class object, but the other way is not possible.
*/

#include <iostream>
using namespace std;

class Base
{
protected:
    int i;
public:
    Base(int a) : i(a) 
    { 
	//cout << "base ctor a :" << a << endl; 
    }
    ~Base() {cout << "---- base dtor -----" << endl; }
    virtual void display()
    { cout << "I am Base class object, i = " << i << endl; }
};
 
class Derived : public Base
{
    int j;
public:
    Derived(int a, int b) : Base(a), j(b) 
    { 
     	//cout << "derived ctor a : " << a << " b : "  << b << endl;
    }
    ~Derived() {cout << "---- derived dtor -----" << endl; }
    virtual void display()
    { cout << "I am Derived class object, i = "
           << i << ", j = " << j << endl;  }
};
 
// Global method, Base class object is passed by value
void somefunc (Base obj)
{
    obj.display();
}

// object is passed by reference. Here there will be no object slicing
void somefunc2 (Base &obj)
{
    obj.display();
}
 
void somefunc3 (Base *objp)
{
    objp->display();
}

int main()
{
    //Base b(33);
    //Derived d(45, 54);
    //cout << "---------- Object slicing as object is passed by value -----------" << endl;
    //somefunc(b);
    //somefunc(d);  // Object Slicing, the member j of d is sliced off

    //cout << "---------- No object slicing as object is passed by reference ----------------" << endl;
    //somefunc2(b);
    //somefunc2(d);  // No Object Slicing

    cout << "----------- No object slicing as object is passed by pointer --------------" << endl;
    //Base *bp = new Base(66) ;
    Base *dp = new Derived(78, 94);
    //somefunc3(bp);
    somefunc3(dp);  // No Object Slicing
  
    delete dp;   // calls base dtor if non virtual

    return 0;
}



