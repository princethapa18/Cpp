/* 11 Mar 2022
   ****** Iterators revision ********
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
    float x, y;
    explicit Point(float a = 0.f, float b = 0.f) : x{a}, y {b} {}
};

struct Test
{
    int val;
    explicit Test(int x = 0) : val{x} {}
};

// gives a max heap
struct CompareValLesser {
    bool operator()(Test const& p1, Test const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.val < p2.val;
    }
};

// Need to understand how this works
struct CompareValGreater 
{
    bool operator()(Test const& p1, Test const& p2)
    {
        return p1.val > p2.val;
    }
};

int main()
{
    vector<Point*> vec;
    float x = 1.2f, y = 2.5f;
    vec.emplace_back( new Point{++x, ++y} );
    vec.emplace_back( new Point{++x, ++y} );
    vec.emplace_back( new Point{++x, ++y} );
    vec.emplace_back( new Point{++x, ++y} );
    vec.emplace_back( new Point{++x, ++y} );

    for(Point * p : vec)
    {
        cout << p << " (*p).x " << (*p).x << " p->x " << p->x << endl;
    }

    for(auto &it : vec)
    {
        // the type deduced for it   --> of Point* type    
        // it is deduced to   Point * it

        cout <<  it  << " x:" << (*it).x << " y: " << (*it).y <<  endl;
        //cout << it->x << endl; okay     (*it).x is same as it->x

        //cout << " it.x " << it.x << endl;
        // error: request for member ‘x’ in ‘it’, which is of pointer type ‘Point*’ (maybe you meant to use ‘->’ ?)
        // because it is of pointer type 'Point*'
    }

    for(auto &it : vec)
        delete it;

    vector<Point> vec1;
    vec1.emplace_back( Point{++x, ++y} );
    vec1.emplace_back( Point{++x, ++y} );
    vec1.emplace_back( Point{++x, ++y} );
    vec1.emplace_back( Point{++x, ++y} );

    for(auto &it : vec1)
    {
        // it is deduced to Point  
        // Its like  --->  Point it 
        //cout <<  it  << " x:" << (*it).x << " y: " << (*it).y <<  endl; // error: no match for ‘operator*’ (operand type is ‘Point’)
        cout << " x:" << it.x << " y: " << it.y <<  endl;
        it.x *= 5.f;
        it.y *= 5.f;
    }

    for(auto &it : vec1)
    {
        cout << " x:" << it.x << " y: " << it.y <<  endl;
    }
    /* O/P
    x:7.2 y: 8.5
    x:8.2 y: 9.5
    x:9.2 y: 10.5
    x:10.2 y: 11.5

    x:36 y: 42.5
    x:41 y: 47.5
    x:46 y: 52.5
    x:51 y: 57.5
    */

   {
       //priority_queue<Test, vector<Test> , [](const Test& p1 , const Test& p2) { return p1.val < p2.val;} > minHeap;  was giving some error
       //priority_queue<Test, vector<Test> , CompareValLesser > maxHeap;  // Gives max heap

       //auto greater = [](const Test& p1, const Test& p2) -> bool { return p1.val > p2.val };
       // error: type/value mismatch at argument 3 in template parameter list for ‘template<class _Tp, class _Sequence, class _Compare> class std::priority_queue’
       // priority_queue<Test, vector<Test> , greater > minHeap;
       priority_queue<Test, vector<Test> , CompareValGreater > minHeap; 

       Test t1{4};
       minHeap.push(t1);
       Test t2{3};
       minHeap.push(t2);
       Test t3{6};
       minHeap.push(t3);
       Test t4{7};
       minHeap.push(t4);
       Test t5{1};
       minHeap.push(t5);

       while( !minHeap.empty() )
       {
           Test t = minHeap.top();
           cout << t.val << " ";
           minHeap.pop();
       }
   }

    return 0;
}

/*
 valgrind ./a.out --leak-check=full
==9419== Memcheck, a memory error detector
==9419== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9419== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==9419== Command: ./a.out --leak-check=full
==9419== 
0x5a24040 x:2.2 y: 3.5
0x5a240e0 x:3.2 y: 4.5
0x5a24180 x:4.2 y: 5.5
0x5a24230 x:5.2 y: 6.5
0x5a24280 x:6.2 y: 7.5
==9419== 
==9419== HEAP SUMMARY:
==9419==     in use at exit: 0 bytes in 0 blocks
==9419==   total heap usage: 9 allocs, 9 frees, 160 bytes allocated
==9419== 
==9419== All heap blocks were freed -- no leaks are possible
==9419== 
==9419== For counts of detected and suppressed errors, rerun with: -v
==9419== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
-----------------------------

./a.out 
0xbf8010 (*p).x 2.2 p->x 2.2
0xbf8050 (*p).x 3.2 p->x 3.2
0xbf8030 (*p).x 4.2 p->x 4.2
0xbf8070 (*p).x 5.2 p->x 5.2
0xbf80c0 (*p).x 6.2 p->x 6.2
0xbf8010 x:2.2 y: 3.5
0xbf8050 x:3.2 y: 4.5
0xbf8030 x:4.2 y: 5.5
0xbf8070 x:5.2 y: 6.5
0xbf80c0 x:6.2 y: 7.5
 x:7.2 y: 8.5
 x:8.2 y: 9.5
 x:9.2 y: 10.5
 x:10.2 y: 11.5
 x:36 y: 42.5
 x:41 y: 47.5
 x:46 y: 52.5
 x:51 y: 57.5


*/
