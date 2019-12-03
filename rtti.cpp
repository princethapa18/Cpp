// 24 Nov 2019
/************* Run Time Type Identification  [ only works for POLYMORPHIC classes] *******************************
   
   In C++, RTTI can be used to do safe typecasts, using the dynamic_cast<> operator, 
   and to manipulate type information at runtime, using the typeid operator and std::type_info class. 
   
   RTTI is available only for classes that are    POLYMORPHIC, 
   which means they have    ------>            AT LEAST ONE VIRTUAL METHOD. 
   In practice, this is not a limitation 
   because base classes must have a virtual destructor to allow objects 
   of derived classes to perform proper cleanup if they are deleted from a base pointer.
 
   Classes should have atleast one virtual function
   2 Operators
   typeid(val)             operator    --> if p is 0 or nullptr then typeid(*p) throws bad_typeid exception
   dynamic_cast<type>(val) operator
   
   ********************************* DYNAMIC_CAST OPERATOR ******************************************************
                          Base   ( must have atleast 1 or more virtual function  i.e POLYMORPHIC CLASSES)
                         /   \
                   Derived1  Derived2
		
	Used to convert from  ptr_or_ref_to_Base to ptr_or_ref_to_Derived type     [DOWNCASTING]    {only with ptr or reference } 
		
				   
   The dynamic_cast operator in C++ is used for DOWNCASTING a reference or pointer to a more specific type in THE CLASS HIERARCHY.   
   Unlike the static_cast, the target of the dynamic_cast must be a pointer or reference to class. 
   Unlike static_cast and C-style typecast (where type check is made during compilation), 
   a type safety check is performed at runtime. 
   
   If the types are not compatible, an std::bad_cast exception will be thrown (when dealing with references) or 
                                    a null pointer will be returned (when dealing with pointers)
									
   ************************************ DOWNCASTING ***********************************************************
   Downcasting or type refinement is the act of casting a reference/pointer of a BASE class to one of its DERIVED classes. 
   Base *b = new Derived;
   Derived *d = dynamic_cast<Derived*>(b); // DOWNCASTING    from Base to Derived


*/

#include <iostream>
#include <typeinfo>    // <typeinfo> is included for using typeid(val) operator

using namespace std;
class Base {
    virtual void fun(){}  // if there is no virtual function then B is not POLYMORPHIC
};
class Derived: public Base { };

int main()
{
    /// dynamic_cast with pointers ************************
    Base *base_ptr = new Derived;

    Derived *derived_ptr = dynamic_cast<Derived*>(base_ptr);  // gives compile error:
                                       // cannot dynamic_cast 'base_ptr' (of type 'class Base*') to type 'class Derived*'
                                       // (source type is not polymorphic)
    //Derived *derived_ptr1 = b; // gives compile error: invalid conversion from Base* to Derived*
    Derived *derived_ptr2 = (Derived*)base_ptr; // C-style cast

    if(derived_ptr2 != NULL)
        cout << "works" << endl;
    else
        cout << "cannot cast Base* to Derived*" << endl;

    /// ------------------------------------------------------
    /// *********  dynamic_cast with references **************

    Derived d;
    Base &b_ref = d;
    try{
       Derived &d_ref = dynamic_cast<Derived&>(b_ref);
       cout << "dynamic_cast passes" << endl;
    } catch (bad_cast) {
        cout << "bad_cast exception thrown" << endl;
    }

    // throws exception std::bad_cast
    Base b1;
    Base &b1_ref = b1;

    try{
       Derived &d1_ref = dynamic_cast<Derived&>(b1_ref); // dynamic_cast fails
       cout << "dynamic_cast passes" << endl;
    } catch (bad_cast) {
        cout << "bad_cast exception thrown" << endl;
    }

    /// The typeid operator ---------------------------------------------

    // compare type at run time of 2 objects
    if(typeid(*base_ptr) == typeid(*derived_ptr2))
        cout << " base_ptr and derived_ptr2 point to the same type " << endl;
    else
        cout << " base_ptr and derived_ptr2 do not point to the same type " << endl;

    // test whether run time type is a specific typeid
    // derefence the base_ptr and check whether it points to Derived type or not
    if(typeid(*base_ptr) == typeid(Derived))
        cout << " Yes base_ptr points to the Derived type " << endl;
    else
        cout << " No base_ptr points to the Derived type " << endl;

    // test always fails. The type of base_ptr is pointer to base
    // This test compares Base* to type Derived
    // this is an unequal test and will always fail
    if(typeid(base_ptr) == typeid(Derived))
        cout << " pass " << endl; // code never execute
    else
        cout << " this test always fails " << endl;

    // these 2 tests doesn't make sense
    /*
    if(typeid(base_ptr) == typeid(Derived*))
        cout << " pass " << endl;
    else
        cout << " fail " << endl;   // fails  as base_ptr   [ Base* base_ptr]

    if(typeid(derived_ptr2) == typeid(Derived*))
        cout << " pass " << endl;  // passes
    else
        cout << " fail " << endl;
    */

    Base *pb = nullptr;
    /// Because pb is a nullptr
    /// Therefore typeid(*pb) throws std::bad_typeid  exception
    if (typeid(*pb) == typeid(Derived) )
    {

    }

    /// ------------------------------------------------------


    return 0;
}



