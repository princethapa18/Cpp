/* 18 feb 2019
 * Stack implementation in C++
 * LIFO
 * push(element)      inserts element at the end.   O(1)
 * pop()              removes element from the end. O(1) 
 * peek() or top():   returns top element of stack. O(1)
 * isEmpty():         returns true if stack is empty, else false. O(1)
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

class Stack
{
  int *_items;
  int _max, _num;
public:
  Stack() 
  { 
    //std::cout << " ctor " << endl;
    _max   = 20;
    _items = NULL;
    _num   = 0;
  }
  
  ~Stack() 
  {
    //std::cout << " dtor " << endl;
    free(_items);
  }
  
  void push(int element) 
  {
      if(!_items) 
      {
	_items = (int*) malloc(sizeof(int) * _max);	
      }
      else
      {
	  if(_num == (_max-1) )
	  {
	    _max += 20;
	    //cout << " reallocating " << endl;
	    _items = (int*) realloc(_items, sizeof(int) * _max);
	    
	  }
      }
      
      _items[_num] = element;
      _num++;
  }
  
  int top()
  {
      if(_num == 0) return -1;
      int ret = _items[_num - 1];
      return ret;
  } 
  void pop()
  {
    if(_num == 0) return;
    
    _items[_num - 1] = -1;
    _num--;
  }
};

int main()
{
  Stack obj;
  obj.push(5);
  obj.push(6);
  obj.push(7);
  obj.push(15);
  obj.push(26);
  obj.push(13);
  
  cout << " top() : " << obj.top() << endl;
  cout << " pop() : " << endl;
  obj.pop();
  cout << " top() : " << obj.top() << endl;
  obj.push(35); 
  cout << " top() : " << obj.top() << endl;
  
  return 0; 
}
