/* 18 feb 2019
 * Stack implementation in C++ [template]   
 * LIFO
 * push(element)  inserts element at the end.   O(1)
 * pop(element)   removes element from the end. O(1) 
 * Peek or Top:   Returns top element of stack. O(1)
 * isEmpty:       Returns true if stack is empty, else false. O(1)
 * 
 * for int, double and float
 * 
 */

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

template <typename T>
class Stack
{
  T *_items;
  int _max, _num;
public:
  Stack() 
  { 
    //std::cout << " ctor " << endl;
    _max   = 20;
    _items = NULL;
    _num = 0;
  }
  
  ~Stack() 
  {
    //std::cout << " dtor " << endl;
    free(_items);
  }
  
  void push(T element) 
  {
      if(!_items) 
      {
	_items = (T*) malloc(sizeof(T) * _max);
      }
      else
      {
	  if(_num == (_max-1) )
	  {
	    _max += 20;
	    //cout << " reallocating " << endl;
	    _items = (T*) realloc(_items, sizeof(T) * _max);
	    
	  }	  	  
      }
      
      _items[_num] = element;
      _num++;
  }
  
  void  pop();
  T     top();
  bool  isEmpty();
};

/*
template<typename T>
void Stack<T>::push(T element)
{
  ...
}

template<typename T>
return-type ClassName<T>::functionName(parameters ...)
{
  
}
*/

template<typename T>
void Stack<T>::pop()
{
  if(_num == 0) 
    return;
  _items[_num - 1] = -1;
  _num--;
}

template<typename T>
T Stack<T>::top()
{
  if(_num == 0)
    return 0.0;
  return _items[_num - 1];
}

template<typename T>
bool Stack<T>::isEmpty()
{
  return (_num ? false : true);
}

int main()
{
    Stack<float> obj;
    if(obj.isEmpty())
      cout << " obj.isEmpty() : yes " <<  endl;
    else
      cout << " obj.isEmpty() : no " <<  endl;
    obj.push(5.3);
    obj.push(6.5);
    obj.push(7.9);
    obj.push(15.2);
    obj.push(26.4);
    obj.push(13.3);
    if(obj.isEmpty())
      cout << " obj.isEmpty() : yes " <<  endl;
    else
      cout << " obj.isEmpty() : no " <<  endl;
    cout << " pop() : " <<  endl;
    obj.pop();
    cout << " top() : " << obj.top() << endl;

    Stack<int> obj2;
    obj2.push(5);
    obj2.push(13);

    cout << " top() : " << obj2.top() << endl;
    
    Stack<double> db;
    Stack<int> in;
    cout << " db.top() " << db.top() << endl;
    cout << " in.top() " << in.top() << endl;
    db.push(9.676);
    db.push(11.323);
    db.push(37.54);
    db.pop();
    cout << " db.top() " << db.top() << endl;
    
    return 0; 
}
