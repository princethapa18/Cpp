/* 8 Mar 2022 
   Operator overloading revision
   https://www.geeksforgeeks.org/operator-overloading-c/
   
   In C++, we can make operators to work for user defined classes. 
   This means C++ has the ability to provide the operators with a special meaning for a data type, 
   this ability is known as operator overloading. 
   For example, we can overload an operator ‘+’ in a class like String so that we can concatenate two strings by just using +. 
   Other example classes where arithmetic operators may be overloaded are Complex Number, Fractional Number, Big Integer, etc.

   Can't overload .(dot) , :: , sizeof ,  ?: 

   To do
   Overloading
   1. postfix and prefix
   int x = 5;
   int y = x++; // post fix. First assigns then increments 
   O/P --> y = 5 , x = 6 

   prefix
   int x = 5;
   int y = ++x;
   O/P --> y = 6, x = 6; // increments x and then assigns its value to y

   2. []  subscript operator

   3. -> (arrow)  and * (dereference) operator

   4. new and delete

   5. << ,  >> operator   [extraction and insertion operator]
*/
#include <iostream>
using namespace std;


class Point
{
    int x;
    int y;
public:
    explicit Point(int a = 0, int b = 0) : x{a}, y{b} {}

    Point(const Point & obj)
    {
        x = obj.x;
        y = obj.y;
    }

    Point& operator=(const Point & obj)
    {
        if(this != &obj)
        {
            x = obj.x;
            y = obj.y;
        }
        return *this;
    }

    int getX() const {return x;}
    int getY() const {return y;}
    void setX(int a) { x = a;}
    void setY(int b) { y = b;}

    Point& operator++ ();    // prefix ++   // return by reference
    Point  operator++ (int); // postfix ++   // return by value 

    friend ostream& operator << (ostream & os, const Point & obj);
    friend istream& operator >> (istream & is, Point & obj);
};

// Prefix ++i
Point& Point::operator++()
{
    cout << "\nprefix increment operator";
    x++;
    y++;
    return *this;
}
// Postfix  i++
Point Point::operator++(int)
{
    cout << "\npostfix increment operator";
    Point temp{*this}; // save current value
    ++(*this);  // advance one element, checking the increment 
    return temp;
}

// global functions
ostream& operator << (ostream & os, const Point & obj)
{
    os << " x : " << obj.getX() << " y : " << obj.getY() << "\n"; 
    return os;
}

istream& operator >> (istream & is, Point & obj)
{
    int x{-1}, y{-1};
    cout << "\nenter x: ";
    cin >> x;
    obj.setX(x);
    cout << "\nenter y: ";
    cin >> y;
    obj.setY(y);
    return is;
}

int main()
{
    int x = 5;
    int y = x++;
    cout << "\n y : " << y << " x : " << x;

    int a = 8;
    int b = ++a;
    cout << "\n a : " << a << " b : " << b << endl;

    Point p1{2, 6};
    cout << "p1: " << p1 << endl;

    Point p2 = p1++; // postfix
    cout << "p1: " << p1 << "p2: " << p2 << endl;

    Point p3 = ++p1; // prefix
    cout << "p1: " << p1 << "p3: " << p3 << endl;

    Point p4;
    cin >> p4;
    cout << "p4: " << p4;
    return 0;
}

/* O/P
./a.out 

 y : 5 x : 6
 a : 9 b : 9
p1:  x : 2 y : 6


postfix increment operator
prefix increment operatorp1:  x : 3 y : 7
p2:  x : 2 y : 6


prefix increment operatorp1:  x : 4 y : 8
p3:  x : 4 y : 8


enter x: 10 

enter y: 16
*/