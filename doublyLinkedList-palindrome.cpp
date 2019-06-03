/* 26 Feb 2019 
   doubly linked list
   palindrome problem
*/
#include <iostream>

using namespace std;

class Node {
public:
    Node *next, *prev;
    int data;
    Node() {
        next = NULL;
        prev = NULL;
        data = 0;
    }
};

class MyLinkedList {
    Node *head, 
         *tail;
    int  num;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        num  = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= num) return -1;
        
        int count = 0;
        Node *itr = head;
        
        while(itr && count != index)
        {
            itr = itr->next;
            count++;
        }
        
        return itr->data;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *newnode = new Node();
        newnode->data = val;
        
        if(!head)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev    = newnode;
            head = newnode;
        }
        num++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *newnode = new Node();
        newnode->data = val;
        if(!head)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next    = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        num++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > num) return;
        
        Node *newnode = new Node();
        newnode->data = val;
        
        if(!head && index == num)
        {
            head = newnode;
            tail = newnode;
        }
        else if(head && index == num)
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        else
        {
            int count = 0;
            Node *itr = head, *prev = NULL;
            while(itr && count != index)
            {
                itr = itr->next;
                count++;
            }
            
            prev = itr->prev;
            prev->next    = newnode;
            newnode->prev = prev;

            newnode->next = itr;
            itr->prev     = newnode;
        }
        
        num++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= num) return;
        
        Node *prev = NULL, *itr = head, *next = NULL;
        
        if(index == (num-1))
        {
            if(tail == head)
            {
                delete(tail);
                num--;
                return;
            }
            
            prev = tail->prev;
            delete(tail);
            prev->next = NULL;
            tail = prev;
        }
        else
        {
            int count = 0;
            while(itr && count != index)
            {
                count++;
                itr = itr->next;
            }
            
            prev = itr->prev;
            next = itr->next;
            delete(itr);
            prev->next = next;
            next->prev = prev;
        }
        
        num--; 
    }
    
    void print() 
    {
	if(!head) return;
	Node *itr = head;	
	while(itr)
	{
	    cout << itr->data << " --> ";
	    itr = itr->next;
	}
	
	cout << endl;
    }
    
    Node *reverse(Node *head)
    {
	if(!head) return NULL;
	Node *oldhead = head, *itr = head->next, *next = NULL;
	
	while(itr)
	{
	    next = itr->next;
	    oldhead->next = next;
	    itr->next = head;
	    head = itr;
	    itr = next;
	}
	return head;
    }
    
    bool isPalindrome()
    {
	if(!head) return true;
	Node *mid1 = NULL, *mid2 = NULL, *sptr = head, *fptr = head;
	
	while(sptr && fptr && fptr->next)
	{
	    if(fptr->next && !fptr->next->next)
	      mid1 = sptr;
	    
	    sptr = sptr->next;
	    fptr = fptr->next->next;
	}
		
	mid2 = sptr;       
	if(!mid1) 
	  mid1 = mid2;
	
	cout << " mid1 " << mid1->data << endl;
	cout << " mid2 " << mid2->data << endl;
	
	if(mid1 != mid2 && (mid1->data != mid2->data) )
	  return false;
		
	Node *headSec = NULL, *secItr = NULL, *firstItr = head;
	headSec = reverse(mid2->next);
	secItr = headSec;
	bool ret = true;
	
	mid2->next = headSec;
	cout << " linked list after second half reversed " << endl;
	print();
	
	while( (firstItr && firstItr != mid1) && secItr)
	{
	    if( firstItr->data != secItr->data)
	    {
		ret = false;
	        break;
	    }
	    
	    firstItr = firstItr->next;
	    secItr   = secItr->next;
	    
	}
	
	headSec = reverse(headSec);
	mid2->next = headSec;
	return ret;  
    }
    
};



int main()
{
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(2);
    obj->addAtTail(3);
    obj->addAtTail(2);
    obj->addAtTail(1);
    cout << "original linked list" << endl;
    obj->print();
    if(obj->isPalindrome())
      cout << "is palindrome : yes" << endl;
    else
      cout << "is palindrome : no" << endl;
    obj->print();
    return 1;
}

