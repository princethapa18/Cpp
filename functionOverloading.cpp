/* *********** Function Overloading  Week 29  15 July
   Function overloading or method overloading is the ability to create multiple functions 
   of the same name with different implementations. 
   Calls to an overloaded function will run a specific implementation of that function 
   appropriate to the context of the call, allowing one function call to perform different tasks depending on context. 

   Rules in function overloading
   --> The same function name is used for more than one function definition
   --> The functions must differ either by the no. of arguments or types of their parameters

   Which function to use for a particular call is resolved at compile time

   Complications
   Name masking (due to scope) and Implicit type conversion causes ambiguity

    1.  Type Conversion.
    2.  Function with default arguments.
    3.  Function with a pass by reference.

    https://en.wikipedia.org/wiki/Function_overloading
    https://www.geeksforgeeks.org/function-overloading-c/
*/
#include <iostream>
using namespace std;

class Math
{
public:
    /* Type conversion */
    int add(int a, int b)
    {
        cout << "add function with 2 int arguments " << endl; 
        return (a + b);
    }
    /*
    float add(int a, int b)
    {
        cout << "add function with 2 int arguments " << endl; 
        return (a + b);
    }
    functionOverloading.cpp:27:11: error: ‘float Math::add(int, int)’ cannot be overloaded
    float add(int a, int b)  
    Because the argument types are same
    */

    /* function overloaded as no. of arguments is different */
    float add(int a, int b, int c)
    {
        cout << "add function with 3 int arguments " << endl; 
        return (a + b + c);
    }

    float add(float a, float b)
    {
        cout << "add function with 2 float arguments " << endl; 
        return (a + b);    
    }
    float add(double a, double b)
    {
        cout << "add function with 2 double arguments " << endl; 
        return static_cast<float>(a + b);    
    }

    // Functions with single parameter
    // Ambiguity
    int test(int a)
    {
        cout << "test(int a)" << endl;
        return a++;
    }
    int test(float a)
    {
        cout << "test(float a)" << endl;
        return static_cast<int>(a++);
    }
};

/* Function with default arguments*/ 
int fun(int x)
{
    cout << "fun(int x)" << endl;
    return x++;
}

int fun(int x, int y = 12)
{
    cout << "fun(int x, int y)" << endl;
    return (x+y);
}

/* Function with a Pass by Reference */
void fun1(int x)
{
    cout << "fun1(int x)" << endl;
}
// void fun1(int& x)
// {
//     cout << "fun1(int& x)" << endl;
// }
// void fun1(const int& x)
// {
//     cout << "fun1(const int& x)" << endl;
// }
void fun1(int* x)
{
    cout << "fun1(int* x)" << endl;
}

/* Can't overload these functions

int fun(int *ptr);
int fun(int ptr[]); // redeclaration of fun(int *ptr)

-> Parameter declarations that differ only in that one is a function type and the other is a pointer to the same function type are equivalent.

void h(int ());  // parameter is a function type
void h(int (*)()); // redeclaration of h(int())   parameter is a pointer to a function type

-> The const and volatile type-specifiers for each parameter type are ignored when determining which function is being declared, defined, or called
int f ( int x) {
    return x+10;
}
int f ( const int x) {
    return x+10;
}
n particular, for any type T,
“pointer to T,” “pointer to const T,” and “pointer to volatile T” 
are considered distinct parameter types, as are “reference to T,” “reference to const T,” and “reference to volatile T

*/

// https://www.stroustrup.com/bs_faq2.html#overloadderived
// Why doesn't overloading work for derived classes?
class B {
	public:
		int f(int i) { cout << "f(int): "; return i+1; }
		// ...
	};

class D : public B {
public:
    double f(double d) { cout << "f(double): "; return d+1.3; }
    // ...
};

/* 
   D* pd = new D;
   cout << pd->f(2) << '\n';      // prints f(double) : 3.3   not f(int) : 3
   cout << pd->f(2.3) << '\n';    // prints f(double) : 3.6

   int f(int i) is in B's scope
   There is no overload resolution between D and B. 
   The compiler looks into the scope of D, finds the function "double f(double)" and calls it.
   It never bothers with the (enclosing) scope of B.
   In C++, there is no overloading across scopes.
*/


/*  But what if I want to create an overload set of all my f() functions from my base and derived class? That's easily done using a using-declaration:  */

class D1 : public B
{
public:
    using B::f; // make every f from B available
    double f(double d)
    {
        cout << "f(double): "; return d+1.3;   
    }
};

int main()
{
    // 1. Type conversion
    //Math mth;
    // int x   = mth.add(5, 6);
    // float f = mth.add(4, 5, 6);
    // cout << "x " << x  << " f " << f << endl;
    // int i   = mth.add(4, 5); // add function with 2 int arguments
    // float f = mth.add(1, 3); // add function with 2 int arguments

    // float f1 = mth.add(1.3f, 3.5f);// add function with 2 float arguments
    // float f2 = mth.add(3.3, 6.8);  // add function with 2 double arguments 
    // float f3 = mth.add(13.3, 16.8);// add function with 2 double arguments
    
    //mth.test(3.4);  // 3.4 is a double but there is no test(double)  function
    //functionOverloading.cpp:86:17: error: call of overloaded ‘test(double)’ is ambiguous
    //mth.test(3.4);

    // cout << mth.test('a') << endl;

    // char c = 'b';
    // cout << mth.test(c) << endl;

    ///-----------------
    // 2. Function with default arguments
    //cout << fun(4 , 2) << endl;  // calls overloaded fun(int x, int y)   prints 6 ok no problem
    //cout << fun(4) << endl;  // this causes ambiguity . Which function to call fun(int x) or overloaded function fun(int x, int y)
    //functionOverloading.cpp:115:18: error: call of overloaded ‘fun(int)’ is ambiguous

    // 3. Function with a Pass by reference
    //int x = 5;
    //fun1(x);
    //functionOverloading.cpp:130:11: error: call of overloaded ‘fun1(int&)’ is ambiguous
    //fun1(x);

    ///-------------------
    // 4. Function overloading in derived classes doesn't work 
    D* pd = new D;
	cout << pd->f(2) << '\n';      // prints f(double) : 3.3   not f(int) : 3
	cout << pd->f(2.3) << '\n';    // prints f(double) : 3.6
    /*
       There is no overload resolution between derived class D and base class B.
       The compiler looks into the scope of D, finds the single function "double f(double)" and calls it.
       It never bothers with the (enclosing) scope of B. In C++, there is no overloading across scopes - derived class scopes are not an exception to this general rule.
    */

    D1* pd1 = new D1;
	cout << pd1->f(2) << '\n';      // prints f(int)    : 3.3
	cout << pd1->f(2.3) << '\n';    // prints f(double) : 3.6

    return 0;
}


/*

Function Overloading VS Function Overriding:

    1. Inheritance: 
       Overriding of functions occurs when one class is inherited from another class. Overloading can occur without inheritance.
    2. Function Signature: 
       Overloaded functions must differ in function signature ie either number of parameters or type of parameters should differ. 
       In overriding, function signatures must be same.
    3. Scope of functions: 
       Overridden functions are in different scopes; whereas overloaded functions are in same scope.
    4. Behavior of functions: 
       Overriding is needed when derived class function has to do some added or different job than 
       the base class function. Overloading is used to have same name functions which behave differently depending upon parameters passed to them.


*/