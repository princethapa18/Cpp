// 22june 18
// constructor
// if no constructor defined compiler initializes using a default constructor


#include <iostream>
using namespace std;
class Node
{
    int id;
    float x, y, z;
public:
    //Node(): id(0), x(0.f), y(0.f), z(0.f) { }
    Node(int i = 0, float a = 0.f, float b = 0.f, float c = 0.f): id(i), x(a), y(b), z(c) { }
    void printId() {
        cout << "id: " << id << endl;
    }
    void printCoord() {
        cout << "x y z: " << x << " " << y << " " << z << endl;
    }

};

/*
A copy constructor is a member function which initializes an object using another object of the same class.
A copy constructor has the following general function prototype:
ClassName (const ClassName &old_obj);
*/
class Point
{
    int x, y;
public:
    Point():x(0), y(0) {cout << "normal ctor with no parameters" << endl;} // using initializer list
    Point(int x1, int y1):x(x1),y(y1) { cout << "parameterized ctor" << endl;} // using initializer list
    /* Explicit or User-Defined Copy ctor */
    // we need to define our own copy ctor incase there are pointers or shared references (DEEP COPY)
    // because implicit or default copy ctor simply copies all the data members (SHALLOW COPY)
    // There will be 2 pointers pointing to the same address.
    Point(const Point &obj)
    {
        x = obj.x;
        y = obj.y;
        cout << "copy ctor" << endl;
    }
    // WHY OBJ IS PASSED BY REFERENCE IN COPY CTOR?
    // bc copy ctor is called when:
    // 1) object is initialized by another object of the same class
    // 2) object is passed by value to a function, and
    // 3) object is returned by value from a function
    // When obj is passed by value in a copy ctor it calls another copy ctor which calls another ctor and so on
    // it becomes a non terminating chain
    // Therefore never do this : Point(const Point obj) // Never pass an object by value in a copy ctor
    // WHY OBJ IS CONST?
    // It makes sure that the obj is not modified

    /* Overloaded Assignment operator */
    Point& operator=(const Point &obj)
    {
        x = obj.x;
        y = obj.y;
        cout << "assignment operator" << endl;
        return *this;
    }

    int getX() {return x;}
    int getY() {return y;}
};

int main()
{
    /*
    Node obj;
    obj.printCoord();
    obj.printId();
    Node obj2(1, 1.2, 2.5, 3.5);
    Node obj3 = obj2; // copy
    obj3.printCoord();
    obj3.printId();
    */

    Point p1(1, 3); // parameterized ctor
    Point p2 = p1; //  copy ctor
    Point p3(p1); //   copy ctor
    //Point p4;
    //p4 = p1; // copy thru assignment

    Point p5; // normal ctor with no parameters
    p5 = p1; // copy thru assignment

    cout << "x: " << p3.getX() << endl;
    cout << "y: " << p5.getY() << endl;

    return 0;
}
