/* 10 Mar 2022
   Private constructor  
   Private destructor

   A friend knows your private things

   https://www.geeksforgeeks.org/can-constructor-private-cpp/
   https://www.geeksforgeeks.org/private-destructor-in-cpp/

   https://stackoverflow.com/questions/631783/what-is-the-use-of-having-destructor-as-private

*/
#include <iostream>
using namespace std;

namespace PrivateCtor
{
    /* Can a constructor be private ? Yes

    1. Using a friend class
        Only the friend class can instantiate it. 
    2. Used in singleton 
    3. Named Constructor Idiom :  (todo)
        Since constructor has same name as of class, 
        different constructors are differentiated by their parameter list, but if numbers of constructors is more, 
        then implementation can become error prone.
        With the Named Constructor Idiom, you declare all the class’s constructors in the private or protected sections, 
        and then for accessing objects of class, you create public static functions.
    */

    class A
    {
    public:
        // A create() 
        // {
        //     A a;
        //     return a;  // Is function kaise kal karenge agar object hi create nahi hua to
        //     // To ye  kaam nahi karega
        // }

        static A getInstance()
        {
            cout << " inside getInstance() \n";
            A a;
            return a;
        }
    private:
        A()
        {
            cout << " A's ctor \n";
        }

        friend class B;  // using friend class
        friend A getA(); // using friend function
    };

    A getA()
    {
        cout << " inside global friend function getA()\n";
        A a;
        return a;
    }

    class B
    {
    public:
        B() 
        {
            A a1;
            cout << " B's ctor\n";    
        }
    };
}

namespace PrivateDtor
{
    class Test
    {
        public:
        Test() { cout << " Test ctor\n"; }
        friend void deleteTest(Test *);
        private:
        ~Test() { cout << " Test dtor\n"; }
    };

    void deleteTest(Test * ptr)
    {
        delete ptr;
    }
}

namespace DontAllowAllocationOnHeap
{
    class CantCreateOnHeap
    {
        public:
        CantCreateOnHeap() { cout << " CantCreateOnHeap ctor\n";}
        ~CantCreateOnHeap() { cout << " CantCreateOnHeap dtor\n";}
        private:
        void* operator new(size_t size)
        {
            void *p = ::operator new(size);
            return p;
        }
        void operator delete(void *p)
        {
            free(p);
        }
    };
}

int main()
{
    {
        using namespace PrivateCtor;
        B b1;
        A a2 = getA(); // this also works
        A a = A::getInstance();
    }

    {
        using namespace PrivateDtor;
        Test * ptr_test = new Test;
        // Can't delete
        // delete ptr_test; // private-ctor-dtor.cpp:82:9: error: ‘PrivateDtor::Test::~Test()’ is private
        deleteTest(ptr_test);

        {
            //Test t;
            //Test *p = &t;
            // private-ctor-dtor.cpp:83:9: error: ‘PrivateDtor::Test::~Test()’ is private
            //~Test() { cout << " Test dtor\n"; }
            // deleteTest(p); this also gives the same error as above
        }
    }

    {
        using namespace DontAllowAllocationOnHeap;
        // CantCreateOnHeap *ptr = new CantCreateOnHeap;
        /* This gives following errors
        private-ctor-dtor.cpp:100:15: error: ‘static void* DontAllowAllocationOnHeap::CantCreateOnHeap::operator new(size_t)’ is private
        void* operator new(size_t size)
               ^
        private-ctor-dtor.cpp:139:37: error: within this context
        CantCreateOnHeap *ptr = new CantCreateOnHeap;
                                     ^
        private-ctor-dtor.cpp:105:14: error: ‘static void DontAllowAllocationOnHeap::CantCreateOnHeap::operator delete(void*)’ is private
        void operator delete(void *p)
              ^
        private-ctor-dtor.cpp:139:37: error: within this context
        CantCreateOnHeap *ptr = new CantCreateOnHeap;
                                     ^
        private-ctor-dtor.cpp:105:14: error: ‘static void DontAllowAllocationOnHeap::CantCreateOnHeap::operator delete(void*)’ is private
        void operator delete(void *p)
              ^
        private-ctor-dtor.cpp:139:37: error: within this context
        CantCreateOnHeap *ptr = new CantCreateOnHeap;
        */

        CantCreateOnHeap obj;  // this is okay
    }
    return 0;
}

/* O/P

 A's ctor 
 B's ctor
 inside global friend function getA()
 A's ctor 
 inside getInstance() 
 A's ctor 
 Test ctor
 Test dtor
 CantCreateOnHeap ctor
 CantCreateOnHeap dtor
*/


