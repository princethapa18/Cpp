#include <iostream>
using namespace std;

template <class T>
class SmartPtr
{
	T *ptr;
public:
        explicit SmartPtr(T *p = NULL) {ptr = p; }        
        ~ SmartPtr() {delete ptr; }
        
        T & operator * () {return *ptr; }   // overloading dereferencing operator
        T * operator -> () {return ptr; }   // overloading arrow operator
};

typedef struct NodeS 
{
	int nid;
        float xyz[3];
} NodeS;

int main()
{
	SmartPtr<int> p(new int(4));
        cout << *p << endl;
       
        SmartPtr<NodeS> nod(new NodeS());
        nod->nid = 2456;
        nod->xyz[0] = 0.567;
        nod->xyz[1] = 0.867;
        nod->xyz[2] = 0.650;

        cout << nod->xyz[1] << endl; 

	return 0;
}
