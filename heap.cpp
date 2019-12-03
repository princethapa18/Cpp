/* 7 Feb 2019
 Heap implementation using class
 insert()
 findMax() or findMin()
 deleteMax() or deleteMin()

*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template<class T>
class Heap {
    vector<T> m_heap;
    int  Left(int parent);  // O(1) 2*i + 1
    int  Right(int parent); // O(1) 2*i + 2
    int  Parent(int child); // O(1) (i-1)/2
    void heapifyup(int index);   // O(logn)
    void heapifydown(int index); // O(logn)
public:
    Heap() {}
    void Insert(T element); // push_back() insert at the end and then heapify-up O(logn)
    void DeleteMin();  // delete min i.e root [assuming min heap]
                       // delete root i.e m_heap[0]
                       // then swap it with last element then heapify down.  O(logn)
    int  ExtractMin(); // peek() return index of min element O(1)
    void DisplayHeap();
    int Size() {return m_heap.size();}
    int findMinIdx(int parent);
};
template<class T>
int Heap<T>::Left(int parent)
{
    int i = 2 * parent + 1;
    return ( i < m_heap.size() ? i : -1 );
}
template<class T>
int Heap<T>::Right(int parent)
{
    int i = 2 * parent + 2;
    return ( i < m_heap.size() ? i : -1 );
}
template<class T>
int Heap<T>::Parent(int child)
{
    if(child == 0) return -1;
    else return (child - 1)/2;
}
template<class T>
void Heap<T>::Insert(T element)
{
    int newchildIdx = m_heap.size();
    cout << "Insert " << element << " at index " << newchildIdx << endl;
    m_heap.push_back(element);
    if(newchildIdx > 0)
    {
        //cout << "heapifyup element " << element << " new index: " << newchildIdx << endl;
        heapifyup(newchildIdx);
    }
}
template<class T>
void Heap<T>::heapifyup(int index)
{
    int parentIdx = Parent(index);
    //cout << "parent idx : " << parentIdx << " child idx: " << index <<endl;
    if(parentIdx < 0) return;
    if( index >= 0 && m_heap.at(index) < m_heap.at(parentIdx))
    {
        swap(m_heap.at(index), m_heap.at(parentIdx));
        heapifyup(parentIdx);
    }
}
template<class T>
void Heap<T>::DeleteMin()
{
    // delete the parent (root element which is the smallest element)
    // swap the last element from the root;
    // move the root element down the heap tree
    if(m_heap.empty()) { cout << "heap is empty"; return;}

    m_heap.at(0) = m_heap.at(m_heap.size() - 1);
    m_heap.pop_back();

    heapifydown(0);
}
template<class T>
int Heap<T>::findMinIdx(int parent)
{
    int left   = Left(parent);
    int right  = Right(parent);
    int minIdx = parent;
    if(left < m_heap.size() && m_heap.at(left) < m_heap.at(parent))
        minIdx = left;
    if(right < m_heap.size() && m_heap.at(right) < m_heap.at(minIdx))
        minIdx = right;
    return minIdx;
}
template<class T>
void Heap<T>::heapifydown(int index)
{
    int minIdx = findMinIdx(index);
    if(minIdx != index)
    {
        swap(m_heap.at(minIdx), m_heap.at(index));
        heapifydown(minIdx);
    }
}
template<class T>
int Heap<T>::ExtractMin()
{
    if(m_heap.empty())
    {
        cout << "heap is empty";
        return -1;
    }

    return m_heap.at(0);
}
template<class T>
void Heap<T>::DisplayHeap()
{
    for(int i = 0; i < m_heap.size(); i++)
    {
        cout << i << ": " << m_heap.at(i) << endl;
    }
}

int main()
{
    Heap<float> h;
    h.Insert(3.1);
    h.Insert(5.2);
    h.Insert(6.5);
    h.Insert(8.4);
    h.Insert(2.3);
    h.DisplayHeap();
    h.Insert(1.6);
    h.DisplayHeap();
    h.Insert(1.2);
    h.DisplayHeap();

    cout << "delete min "<< endl;
    h.DeleteMin();
    h.DisplayHeap();

    h.Insert(4.3);
    h.DisplayHeap();

    /*
    while (1)
    {
        cout<<"------------------"<<endl;
        cout<<"Operations on Heap"<<endl;
        cout<<"------------------"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Minimum Element"<<endl;
        cout<<"3.Extract Minimum Element"<<endl;
        cout<<"4.Print Heap"<<endl;
        cout<<"5.Exit"<<endl;
        int choice, element;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element to be inserted: ";
            cin>>element;
            h.Insert(element);
            break;
        case 2:
            h.DeleteMin();
            break;
        case 3:
            cout<<"Minimum Element: ";
            if (h.ExtractMin() == -1)
            {
                cout<<"Heap is Empty"<<endl;
            }
            else
                cout<<"Minimum Element:  "<<h.ExtractMin()<<endl;
            break;
        case 4:
            cout<<"Displaying elements of Hwap:  ";
            h.DisplayHeap();
            break;
        case 5:
            exit(1);
        default:
            cout<<"Enter Correct Choice"<<endl;
        }
    }
    */
    return 0;
}
