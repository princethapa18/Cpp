// 8 June 2018 Friday
/* 
Function pointer

One of the most useful things to do with function pointers is pass a function as an argument to another function. 
Functions used as arguments to another function are sometimes called callback functions.

Callback Functions
When a reference to a function (fun pointer) is given as 
an argument to another function.

Processing-function(callbackfun as argument) ---> calls callback fun when required

( 2 Fundamental flaws in callback mechanism
    1) Not type safe
    2) Callback is strongly dependent on processing function
)

*/

#include "stdio.h"
int foo()
{
   printf("inside foo function\n"); 
   return 5;
}
 
int goo()
{
    printf("inside goo function\n"); 
    return 6;
}
 
float boo()
{
    printf("inside boo function\n"); 
    return 8.5;
}

void add(int a, int b)
{
    printf("inside add function\n"); 
    printf("a + b is %d\n", a+b);
}

void subtract(int a, int b)
{
    printf("inside subtract function\n"); 
    printf("a - b is %d\n", a-b);
}

/* processFun() 
   Parameters
   function pointer
   int a
   int b
*/
void processFun(void (*fun)(int,int), int a, int b)
{
    printf("inside processFun function\n");
    printf("a:%d b:%d\n", a, b);
    (*fun) (a, b); 
}

int main()
{
    /*
    int (*fcnPtr)() = foo; // fcnPtr points to function foo()
    printf("%d\n", fcnPtr()); // calls function foo()

    fcnPtr = &goo; // fcnPtr now points to function goo()
    //fcnPtr = goo(); //this is wrong as goo() calls func goo()

    //printf("%d\n", fcnPtr); // prints address of function goo()
    printf("%d\n", fcnPtr());  // calls function goo() 
	
    //fcnPtr = &boo; // gives warning but compiles :  fcnptr.c:33:12: warning: assignment from incompatible pointer type
    //printf("%f\n", fcnPtr()); // prints 0.000  therefore not type safe
    */

    /* Example of a Callback Function */
    
    void (*fun_ptr)(int, int);           // Declaration of a function pointer to function of return type void and which takes 2 integer arguments

    fun_ptr = &add;                      // fun_ptr points to function add() 
    processFun(fun_ptr, 10, 20);         // processFun() calls function add()

    fun_ptr = &subtract;                 // fun_ptr now points to function subtract()
    processFun(fun_ptr, 30, 10);         // processFun() calls function subtract()
	
    return 0;
}








