/*
  29 Nov 2016
  Derived-Class Constructors

  Each derived constructor initializes its immediate base class in addition to initializing
  its own data members

      A
      |
      B
      |
      C      constructor of C can only invoke ctor of its immediate parent i.e B

      C c1();   A ctor -> B ctor -> C ctor

           A    B
            \  /
             C

           A
         /   \
         B   C           Diamond problem [to be done]
          \ /
           D

       Constructor of Derived class D

  Copy Control and Inheritance


  Calling constructor of a Base class from the constructor of a Derived class
  Order of construction (base to derived)  [ based on order of declaration]
  Order of destruction  (derived to base)
*/

#include <iostream>
#include <string>
using namespace std;

class Base
{
    int m_x, m_y;
public:
    //Base() {cout << "default base ctor" << endl;}
    explicit Base(int a = 0, int b = 0) : m_x(a), m_y(b)
    {
        ///cout << "parameterized base ctor" << endl;
    }
    Base(const Base& other)
    {
        cout << "base copy ctor" << endl;
        m_x = other.m_x;
        m_y = other.m_y;
    }

    /// The assignment operator must, as always, guard against self-assignment.
    Base& operator=(const Base& rhs)
    {
        cout << "base assignment operator" << endl;
        if (this != &rhs)
        {
            m_x = rhs.m_x;
            m_y = rhs.m_y;
        }
        return *this;
    }

    //~Base() {cout << "base dtor" << endl;}

    int getX() {return m_x;}
    int getY() {return m_y;}
};

class Derived : public Base
{
    int m_z;
public:
    //Derived() {cout << "default derived ctor" << endl;}
    explicit Derived(int a = 0, int b = 0, int c = 0) : Base(a, b) , m_z(c)
    {
        ///cout << "parameterized derived ctor" << endl;
    }

    Derived(const Derived& other) : Base(other)
    {
        cout << "derived copy ctor" << endl;
        m_z = other.m_z;
    }
    Derived& operator=(const Derived& rhs)
    {
        cout << "derived assignment operator" << endl;
        if (this != &rhs)
        {
            Base::operator=(rhs);
            m_z = rhs.m_z;
        }
        return *this;
    }

    //~Derived() {cout << "derived dtor" << endl;}
    int getZ() {return m_z;}

};

int main()
{
    Derived d(4, 3); /// Base parametrized ctor ---> Derived parametrized ctor
    Derived d1(d);  /// Base copy ctor -->  Derived copy ctor
    //Derived d2 = d; /// Base copy ctor -->  Derived copy ctor
    Derived d2(3, 5); /// Base parametrized ctor ---> Derived parametrized ctor
    d = d2;  /// Base assignment operator --> Derived assignment operator

    cout << "x: " << d.getX() << " y: " << d.getY() << endl;
    return 0;
}
