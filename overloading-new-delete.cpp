/* 10 March 2022
 * Overloading new and delete operator
 * https://www.geeksforgeeks.org/overloading-new-delete-operator-c/
 * 
 * Can be overloaded globally or for a specific class
 * 
 * Syntax 
 * void* operator new(size_t size);
 * The overloaded new operator receives size of type size_t, 
 * which specifies the number of bytes of memory to be allocated. 
 * The return type of the overloaded new must be void*.
 * The overloaded function returns a pointer to the beginning of the block of memory allocated.
 * 
 * void operator delete(void*);
 * The function receives a parameter of type void*
 * which has to be deleted.
 * Function should not return anything.
 * 
 * NOTE: Both overloaded new and delete operator functions are static members by default. 
 *       Therefore, they don’t have access to this pointer .
 */

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

// global overloading
void * operator new(size_t size)
{
  
  cout << " new operator overloading with size: " << size << endl;
  void * p = malloc(size);
  return p;
}

void operator delete(void * p)
{
    cout << " delete operator overloading " << endl;
    free(p);
}


namespace StudentClass
{
  class Student
  {
    string m_name;
    int m_age;
  public:
    Student( )  {cout << "default ctor called\n";}
    ~Student( ) {cout << " destructor called\n"; }
    Student(string name, int age) : m_name{name}, m_age{age} { cout << "parameterized ctor called\n"; }
    friend ostream& operator << (ostream& os, Student * st);
    
    void * operator new(size_t size)
    {
	cout << "overloaded new operator with size: " << size << endl;
	void * p = ::operator new(size);
	//or
	//void *p = malloc(size);  
	return p;
    }
    void operator delete(void * p)
    {
      cout << "overloaded delete operator " << endl;
      free(p);
    }
  };

  ostream& operator << (ostream& os, Student * st)
  {
    os << " name: " << (*st).m_name << " age: " << st->m_age << endl;
    return os;
  }

}

class Test
{
  int x, y;
public:
  explicit Test(int a = 0, int b = 0) : x{a} , y{b} { cout << " Test ctor \n"; }
  ~Test() { cout << " Test destructor\n"; }
};
  
int main()
{
  {
    using namespace StudentClass;
    Student * ptrStudent =  new Student("Prince" , 33);
    cout << ptrStudent;
    delete ptrStudent;
  }
  
  int * ptrNum = new int[5];
  
  delete [] ptrNum;
  
  //Test * ptrTest = (Test*)malloc(sizeof(Test)); // this won't call the constructor
  Test * ptrTest = new Test{4, 5}; // will call the constructor
  delete ptrTest; // this will call the destructor
  //free(ptrTest); // this won't call the destructor;
}

/*
  overloaded new operator with size: 16
  parameterized ctor called
  name: Prince age: 33
  destructor called
  overloaded delete operator  
*/

/*
 new operator overloading with size: 20
 delete operator overloading 
 
 new operator overloading with size: 8
 Test ctor 
 Test destructor
 delete operator overloading 
*/