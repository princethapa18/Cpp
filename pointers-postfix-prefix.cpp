/* 8 Mar 2022
   Pointer revision

    address-of &arr[i] 0x1004050 *(arr + i) : 5
    *arr + i 5
    address-of &arr[i] 0x1004054 *(arr + i) : 10
    *arr + i 6
    address-of &arr[i] 0x1004058 *(arr + i) : 13
    *arr + i 7
    address-of &arr[i] 0x100405c *(arr + i) : 18
    *arr + i 8
    address-of &arr[i] 0x1004060 *(arr + i) : 22
    *arr + i 9

   *(arr + 0)  -->   *(0x1004050)   --> value pointed to by this address is  5
   *(arr + 1)  -->   *(0x1004054)   --> value pointed to by this address is  10

   *arr + 2    -->   *(0x1004050) + 2 --> value pointed to by this address is 5  + 2   = 7

    values
   | 5         |    10       |  13        |    18      |   22      |

       corresponding addresses
   | 0x1004050 |   0x1004054 |  0x1004058 | 0x100405c  | 0x1004060 |

    Assuming arr points to the first element of the array
    
    // post fix
    *arr++   --->  means *(arr++)  --> increments the pointer and dereferences the unincremented address  -->  *(0x1004050++) -->  O/P 5
    // pre fix
    *++arr   --> means *(++arr)    ---> increments the pointer and dereferences the incremented address  -->  *(++0x1004050)  -->  O/P 10

    ++*arr --->  ++(*arr) --> dereference pointer, and increment the value it points to --> O/P   ++(5)

    (*arr)++  --->   (*0x1004050)++ --> O/P (5)++

*/


#include <iostream>
using namespace std;

struct Test
{
    int x;
    int y;
    unsigned int *count;

    explicit Test(int a = 0, int b = 0) : x{a}, y{b} , count{nullptr} 
    {
        if(!count)
            count = new unsigned int(0);
        *count++;
        cout << "in ctor x, y, count " << x << " " << y << " " << count << endl;
    }
    Test(const Test &obj)
    {
        x = obj.x;
        y = obj.y;
        // *count = obj->count; // error: base operand of ‘->’ has non-pointer type ‘const Test’
        // *count = *obj.count ; //gave crash
        count = obj.count;
        *count++;
        cout << "in copy ctor x, y, count " << x << " " << y << " " << count << endl;
    }
    Test& operator=(const Test &obj)
    {
        if(this != &obj)
        {
            x = obj.x;
            y = obj.y;
            //*count = obj->count; // error: base operand of ‘->’ has non-pointer type ‘const Test’
            if(*obj.count)
                *count = *(obj.count);
            *count++;
            cout << "in copy assign operator x, y, count " << x << " " << y << " " << count << endl;
        }
        return *this;
    }

};

int main()
{
    // Test *ptr = new Test(1, 2);
    // cout << " ptr " << ptr << " &ptr " << &ptr << endl;
    // (*ptr).x++;  // same as ptr->x
    // ptr->y++;
    // //*ptr.x++; //  error: request for member ‘x’ in ‘ptr’, which is of pointer type ‘Test*’ (maybe you meant to use ‘->’ ?)
    // cout << "\n(*ptr).x = "  << (*ptr).x <<  " ptr->x = " << ptr->x << endl;
    
    // (*ptr).count++ ; // ptr->count
    // --------------------
    Test p1{3, 4};
    Test p2 = p1;
    Test p3{5, 6};
    p3 = p2;


    cout << "\np1.count " << p1.count << " p2.count " << p2.count << " p3.count " << p3.count << endl; 
    cout << "\n&p1.count " << &p1.count << " &p2.count " << &p2.count << " &p3.count " << &p3.count << endl; 
    cout << "\n*p1.count " << *p1.count << " *p2.count " << *p2.count << " *p3.count " << *p3.count << endl; 

    //-------------------------
    int *arr = new int[5];
    int *arr1 = &arr[0];
    arr[0] = 5;
    arr[1] = 10;
    arr[2] = 13;
    arr[3] = 18;
    arr[4] = 22;

    for(int i = 0; i < 5; i++)
    {
        cout << " address-of &arr[i] " << &arr[i] << " *(arr + i) : " << *(arr + i) << endl;
        cout << " *arr + i " << *arr + i << endl;
    }
    /* O/P  *(arr + 2)    Change the pointers current location by 2 and then dereference it
            *arr + 2      dereference the value pointed to by the pointers current location and add 2 to that value  
    address-of &arr[i] 0x15c1050 *(arr + i) : 5
    *arr + i 5
    address-of &arr[i] 0x15c1054 *(arr + i) : 10
    *arr + i 6
    address-of &arr[i] 0x15c1058 *(arr + i) : 13
    *arr + i 7
    address-of &arr[i] 0x15c105c *(arr + i) : 18
    *arr + i 8
    address-of &arr[i] 0x15c1060 *(arr + i) : 22
    *arr + i 9
    */

    // Acc. to operator precedence rules, the postfix operators, 
    // such as increment and decrement, have higher precedence than prefix operators, such as the dereference operator (*).
    
    cout << " &arr1 " << &arr1 <<  " *arr1 " << *arr1 << endl;

    // post fix   *p++ ----> *(p++)
    // increment pointer and dereference unincremented address
    cout << " &arr1 " << &arr1 << " *arr1++ " << *arr1++ << endl; // equivalent to *(arr1++)

    // prefix  *++p ---> *(++p)
    // increment pointer and dereference incremented address
    cout << " &arr1 " << &arr1 << " *++arr1 " << *++arr1 << endl; // equivalent to *(++arr)

    // ++*p is same as ++(*p)
    // dereference pointer and increment the value it points to
    cout << " &arr1 " << &arr1 << " ++*arr1 " << ++*arr1 << endl; // equivalent to ++(*arr)
    
    // (*p)++   dereference the pointer and increment the value it points to
    cout << " &arr1 " << &arr1 << " (*arr1)++ " << (*arr1)++ << endl; 

    /*  O/P
    &arr1 0x7ffd4dfd7b38 *arr1 5
    &arr1 0x7ffd4dfd7b38 *arr1++ 5
    &arr1 0x7ffd4dfd7b38 *++arr1 13
    &arr1 0x7ffd4dfd7b38 ++*arr1 14
    &arr1 0x7ffd4dfd7b38 (*arr1)++ 14
    */
    return 0;
}

/*
ore was generated by `./pointers'.
Program terminated with signal SIGSEGV, Segmentation fault.
#0  0x0000000000400c4c in Test::Test (this=0x7ffd94848c00, obj=...) at pointers.cpp:31
31              *count = *obj.count;
(gdb) backtrace
#0  0x0000000000400c4c in Test::Test (this=0x7ffd94848c00, obj=...) at pointers.cpp:31
#1  0x0000000000400aee in main () at pointers.cpp:62


 address-of &arr[i] 0x134a050 value pointed to by is 5
 address-of &arr[i] 0x134a054 value pointed to by is 10
 address-of &arr[i] 0x134a058 value pointed to by is 13
 address-of &arr[i] 0x134a05c value pointed to by is 18
 address-of &arr[i] 0x134a060 value pointed to by is 22


*/