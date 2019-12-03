/* 10 April 2019 Copy Vs Assignment operator
   A copy constructor is a special constructor for creating a new object as a copy of an existing object.

When is copy constructor called?

In C++, a Copy Constructor may be called in following cases:
1. When an object of the class is returned by value.
2. When an object of the class is passed (to a function) by value as an argument.
3. When an object is constructed based on another object of the same class.
4. When compiler generates a temporary object.

*/

#include<iostream> 
#include<stdio.h> 
  
using namespace std; 
  
class Test 
{ 
public: 
   Test() 
   { 
	cout<< "default constructor called " <<endl; 
   } 
   Test(const Test &t) 
   { 
      cout<<"Copy constructor called "<<endl; 
   } 
   Test& operator = (const Test &t) 
   { 
      cout<<"Assignment operator called "<<endl; 
   } 

   void fun(Test obj) {  }          // object passed by value. Copy ctor is called
   void fun1(Test &obj) {  }        // object passed by reference . Copy ctor is not called.  
   Test fun2() { return *this; }    // returned by value. Here a copy of an object (*this) is made therefore copy ctor is called here.
   Test& fun3() { return *this; }   // No copy made. Doesn't call the copy ctor.
}; 
  
int main() 
{ 
  //Test t1, t2;   // t1 and t2 are initialized by def. ctor  i.e Test()

  //t2 = t1;       // t2 is assigned the object t1.
                 // calls assignment operator, same as "t2.operator=(t1);"

  //Test t3 = t1;  // copy ctor called.  t3 is initialized using another object t1
                 // same as "Test t3(t1);" 
  //Test t4(t2);   // copy ctor called.  t4 is initialized using another object t2
  //t4.fun(t3);    // copy ctor called as object t3 is passed by value
  //t4.fun1(t1);   // copy ctor is not called as reference of object t1 is passed
 
  Test t4;  // default constructor
  cout << "t4 address " << &t4 << endl; 
  Test &t5 = t4.fun3();                     // fun3() doesn't call copy ctor. Copy ctor not called as t5 is a reference to t4
  cout << "t5 address " << &t5 << endl; 
  Test t6 = t4.fun3();                      // fun3() doesn't call copy ctor. But Copy ctor called as t6 is not a reference
  cout << "t6 address " << &t6 << endl; 
  Test t7 = t4.fun2();                      // fun2() calls copy ctor . Copy ctor called as object is returned by value
  cout << "t7 address " << &t7 << endl;
  return 0; 
} 

