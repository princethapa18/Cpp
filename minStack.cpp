/* 3 June 2019 MinStack problem
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class MinStack {
    vector<int> items;
    vector<int> minItems; // contains list of min items
public:
    /** initialize your data structure here. */
    MinStack() {
        items.reserve(100);
        minItems.reserve(100);
    }
    
    void push(int x) {
        if(items.empty())
        {
            items.push_back(x);
            minItems.push_back(x);
        }
        else 
        {
            items.push_back(x);
            if(x <= minItems.back())
            {
                minItems.push_back(x);
            }
        }
    }
    
    void pop() {
        if(items.empty()) return;
        
        if(items.back() == minItems.back())
        {
            minItems.pop_back();
        }
        
        items.pop_back();
    }
    
    int top() {
        if(items.empty()) return 0;
        return items.back();
    }
    
    int getMin() {
        if(items.empty() || minItems.empty()) return 0;        
        return minItems.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack* obj = new MinStack();
    obj->push(0);
    obj->push(1);
    obj->push(0);
    cout << "obj->getMin() : " << obj->getMin() << endl;
    obj->pop();
    cout << "obj->getMin() : " << obj->getMin() << endl;
  
    return 0;
}
