/* 09 Mar 2022  The diamond problem
         A
        / \
       B   C
        \ /
         D

    Multiple inheritance (inheriting from more than 1 class)

    class A { public: A(int x) { }; };
    class B : public A { public: B(int x) : A{x} { } };
    class C : public A { public: C(int x) : A{x} { } };
    class D : public B, public C { public: D(int x) : B{x}, C{x} { } };

    D d{5};

    A::A(int)
    C::C(int)
    A::A(int)
    B::B(int)
    D::D(int)   

    grand parent A's constructor called twice. Similarly it's destructor will be called twice

    Solution: "virtual" keyword

    class A { public: A(int x) { }; };
    class B : virtual public A { public: B(int x) : A{x} { } };
    class C : virtual public A { public: C(int x) : A{x} { } };
    class D : public B, public C { public: D(int x) : B{x}, C{x} { } };

    D d{5};

    A::A() 
    C::C(int)
    B::B(int)
    D::D(int)

    But grand parent A's default constructor is called.

    How to call grand parent's parameterized constructor?

    class A { public: A(int x) { }; };
    class B : virtual public A { public: B(int x) : A{x} { } };
    class C : virtual public A { public: C(int x) : A{x} { } };
    class D : public B, public C { public: D(int x) : B{x}, C{x}, A{x} { } };

    D d{5};

    A::A(int) 
    C::C(int)
    B::B(int)
    D::D(int)

    https://www.geeksforgeeks.org/multiple-inheritance-in-c/


*/

#include <iostream>
using namespace std;

namespace DiamondProbEx1
{
    class A 
    {
    public:
        A() { cout << "A's ctor\n"; }
        ~A() { cout << "A's dtor\n"; }
    };

    class B : public A 
    {
    public:
        B() { cout << "B's ctor\n"; } 
        ~B() { cout << "B's dtor\n"; } 
    };

    class C : public A 
    {
    public:
        C()  { cout << "C's ctor\n"; } 
        ~C() { cout << "C's dtor\n"; } 
    };
    class D : public B, public C
    {
    public:
        D()  {cout << "D's ctor\n";}
        ~D() {cout << "D's dtor\n";}
    };
}

namespace DiamondProbEx2
{
    class Person
    {
        public:
        Person(int x) { cout << "Person::Person(int ) called\n";}
    }; 

    class Faculty : public Person
    {
    public:
        Faculty(int x) : Person(x)
        {
            cout << "Faculty::Faculty(int) called \n";
        }
    };

    class Student : public Person {
    // data members of Student
    public:
        Student(int x):Person(x) 
        {
            cout<<"Student::Student(int ) called"<< endl;
        }
    };

    // TeachingAssistant
    class TA : public Faculty , public Student 
    {
    public:
        TA(int x):Student(x), Faculty(x)
        {
            cout << "TA::TA(int) called\n";
        }
    };
}

namespace DiamondProbSolution
{
    // using virtual keyword
    class Person {
    public:
        Person(int x)  { cout << "Person::Person(int ) called" << endl;   }
        Person()     { cout << "Person::Person() called" << endl;   }
    };
  
    class Faculty : virtual public Person {
    public:
        Faculty(int x):Person(x)   
        {
            cout<<"Faculty::Faculty(int ) called"<< endl;
        }
    };
  
    class Student : virtual public Person {
    public:
        Student(int x):Person(x) {
            cout<<"Student::Student(int ) called"<< endl;
        }
    };
  
    class TA : public Faculty, public Student  {
    public:
        TA(int x):Student(x), Faculty(x)   {
            cout<<"TA::TA(int ) called"<< endl;
        }
    };

    class TA1 : public Faculty , public Student 
    {
    public:
        TA1(int x):Student(x), Faculty(x), Person(x)
        {
            cout << "TA1::TA1(int) called\n";
        }
    };
}

namespace Order_of_ctor_dtor
{
    class Person
    {
        public:
        Person() { cout << "Person's ctor\n";}
        virtual ~Person() { cout << "Person's dtor\n";}
    };

    class Teacher : public Person
    {
        public:
        Teacher() { cout << "Teacher's ctor\n";}
        ~Teacher() { cout << "Teacher's dtor\n";}
    };

    class Proffesor : public Teacher
    {
        int *m_studentIds{nullptr};
        int m_numStudents;
        int m_profId;
        public:
        Proffesor(int pid = 0, int num = 0) :  m_profId{pid}, m_numStudents{num}
        {  
            cout << "Proffesor's ctor\n";
            if(m_numStudents > 0 && !m_studentIds)
            {
                m_studentIds = new int[m_numStudents];
                cout << " number of students : " << m_numStudents << " &m_studentIds " << &m_studentIds << endl;
            }
        }
        ~Proffesor() 
        { 
            cout << "Proffesor's dtor\n";
            cout << " deleting pointer variable m_studentIds " << &m_studentIds << endl;
            delete[] m_studentIds;
        }
    };

}

int main()
{
    {  /* Diamond problem example 1 */
        DiamondProbEx1::D d;
        /*
            Base class then derived class
            construction order    A -> B -> D     ,  A -> C -> D
            ambiguity
        A's ctor
        B's ctor
        A's ctor
        C's ctor
        D's ctor

        Base class's constructor is called twice.

        Destruction Order   ---> Derived then base
        D's dtor
        C's dtor
        A's dtor
        B's dtor
        A's dtor

        What if there are pointers involved and what happens during destruction?

        */
    }

    {   // Order of construction and destruction   
        using namespace Order_of_ctor_dtor;
        {
            Proffesor prof;
            /*
            Base --> Derived
            Person's ctor
            Teacher's ctor
            Proffesor's ctor

            // without virtual destructor
            Derived --> Base
            Proffesor's dtor
            Teacher's dtor
            Person's dtor
            
            // When virtual destructor is used 
            Proffesor's dtor
            Teacher's dtor
            Person's dtor

            // Here I see no difference
            */            
        }
        cout << " ------------------------------- \n";
        {
            Proffesor * ptr_prof = new Proffesor{};

            delete ptr_prof;
            /*  
            If virtual destructor is not used:

            Person's ctor
            Teacher's ctor
            Proffesor's ctor

            Proffesor's dtor
            Teacher's dtor
            Person's dtor

            If virtual destructor used:
            Person's ctor
            Teacher's ctor
            Proffesor's ctor

            Proffesor's dtor
            Teacher's dtor
            Person's dtor
            
            Here also no differnce.
            */
        }
        // Why and when to use virtual destructor?
        cout << " -----Deleting a derived class object using a pointer of base class type ------------ \n";
        {
            // Base *ptr = new Derived(); // delete ptr;
            Person * ptr = new Proffesor{1, 5}; // derived class
            delete ptr;
            /*
            Non virtual destructor
            Person's ctor
            Teacher's ctor
            Proffesor's ctor

            Person's dtor
            It doesn't call derived class Proffessor's destructor leading to memory leaks

            valgrind ./a.out --tool=memcheck-full
            ==16260== Memcheck, a memory error detector
            ==16260== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
            ==16260== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
            ==16260== Command: ./a.out --tool=memcheck-full
            ==16260== 
           
            -----Deleting a derived class object using a pointer of base class type ------------ 
            Person's ctor
            Teacher's ctor
            Proffesor's ctor
            number of students : 5 &m_studentIds 0x5a23090
            Person's dtor
            ==16260== 
            ==16260== HEAP SUMMARY:
            ==16260==     in use at exit: 20 bytes in 1 blocks
            ==16260==   total heap usage: 3 allocs, 2 frees, 52 bytes allocated
            ==16260== 
            ==16260== LEAK SUMMARY:
            ==16260==    definitely lost: 20 bytes in 1 blocks
            ==16260==    indirectly lost: 0 bytes in 0 blocks
            ==16260==      possibly lost: 0 bytes in 0 blocks
            ==16260==    still reachable: 0 bytes in 0 blocks
            ==16260==         suppressed: 0 bytes in 0 blocks
            ==16260== Rerun with --leak-check=full to see details of leaked memory
            ==16260== 
            ==16260== For counts of detected and suppressed errors, rerun with: -v
            ==16260== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

            Using virtual destructors :
            -----Deleting a derived class object using a pointer of base class type ------------ 
            Person's ctor
            Teacher's ctor
            Proffesor's ctor
            number of students : 5 &m_studentIds 0x24e0018
            
            Calls derived class object's destructor then the base class's destructor.
            No memory leaks

            Proffesor's dtor
            deleting pointer variable m_studentIds 0x24e0018
            Teacher's dtor
            Person's dtor

            $ valgrind ./a.out --leak-check=full 
            ==16958== Memcheck, a memory error detector
            ==16958== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
            ==16958== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
            ==16958== Command: ./a.out --leak-check=full
            ==16958== 
            ...
            -----Deleting a derived class object using a pointer of base class type ------------ 
            Person's ctor
            Teacher's ctor
            Proffesor's ctor
            number of students : 5 &m_studentIds 0x5a230a8
            Proffesor's dtor
            deleting pointer variable m_studentIds 0x5a230a8
            Teacher's dtor
            Person's dtor
            ==16958== 
            ==16958== HEAP SUMMARY:
            ==16958==     in use at exit: 0 bytes in 0 blocks
            ==16958==   total heap usage: 3 allocs, 3 frees, 68 bytes allocated
            ==16958== 
            ==16958== All heap blocks were freed -- no leaks are possible
            ==16958== 
            ==16958== For counts of detected and suppressed errors, rerun with: -v
            ==16958== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

            */
        }
    }
   
    {   // Diamond problem example 2
        cout << "------ Diamond problem Example 2 ----------\n";
        using namespace DiamondProbEx2;
        TA ta1{30};
        /*
        Construction Order
        Person::Person(int ) called
        Faculty::Faculty(int) called 
        Person::Person(int ) called
        Student::Student(int ) called
        TA::TA(int) called

        In the above program, constructor of ‘Person’ is called two times. 
        Destructor of ‘Person’ will also be called two times when object ‘ta1’ is destructed. 
        So object ‘ta1’ has two copies of all members of ‘Person’, this causes ambiguities. 
        The solution to this problem is ‘virtual’ keyword. 
        We make the classes ‘Faculty’ and ‘Student’ as virtual base classes to avoid two copies of ‘Person’ in ‘TA’ class. 
        For example, consider the following program.

        */
    }

    {   // Diamond problem solution
        cout << "------ Diamond problem solution ----------\n";
        using namespace DiamondProbSolution;
        TA ta1(30);
        /*
        Person::Person() called
        Faculty::Faculty(int ) called
        Student::Student(int ) called
        TA::TA(int ) called

        Now constructor of Person is called once.
        But it calls the default constructor.
        When we use ‘virtual’ keyword, the default constructor of grandparent class 
        is called by default even if the parent classes explicitly call parameterized constructor.

        */

       
    }

    {
        using namespace DiamondProbSolution;
        // Diamond problem solution
        cout << "------ Diamond problem solution Example  ----------\n";
        TA1 ta2{9};
        /*
        Person::Person(int ) called
        Faculty::Faculty(int ) called
        Student::Student(int ) called
        TA1::TA1(int) called
        */
    }

    return 0;
}

