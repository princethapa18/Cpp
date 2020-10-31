/* 31 Oct 2020
   ***** Circular Queue using std::vector --->  implementation 2 **********
*/
#include <iostream>
#include <vector>

using namespace std;


class MyCircularQueue {
private:
    //int *m_items;
    std::vector<int> m_items;
    int m_headIdx, m_tailIdx; // head, tail index
    int m_size;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        //m_items = new int[k];
        m_items.resize(k);
        m_size = k;
        m_headIdx = m_tailIdx = -1;
    }
    
    ~MyCircularQueue()
    {
        //delete[] m_items;
    }
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull())
            return false;

        if(isEmpty())
            m_headIdx = 0;
        
        m_tailIdx = (m_tailIdx + 1)%m_size;
        m_items[m_tailIdx] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;    

        if(m_headIdx == m_tailIdx)
        {
            m_headIdx = m_tailIdx = -1;
            return true;
        }

        m_headIdx = (m_headIdx + 1)%m_size; //   if current headIdx = 2 (i.e at the last index) and m_size = 3  then  new headIdx = (2+1)%3 = 0  
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(!isEmpty())
        {
            cout << "head index: " << m_headIdx << endl;
            return m_items[m_headIdx];
        }
        return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(!isEmpty())
        {
            cout << "tail index: " << m_tailIdx << endl;
            return m_items[m_tailIdx];
        }
        return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (m_headIdx == -1);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        
        return ((m_tailIdx + 1)% m_size == m_headIdx);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main()
{
    // MyCircularQueue* obj = new MyCircularQueue(4);
    // obj->enQueue(2);
    // obj->enQueue(3);
    // obj->enQueue(4);
    // obj->enQueue(5);
    // obj->deQueue();
    // obj->enQueue(7);
    // obj->enQueue(9);  // can't enque because circular queue is full
    // obj->deQueue();
    // obj->enQueue(9);
    // obj->deQueue();
    // obj->deQueue();
    // obj->deQueue();
    // obj->deQueue();
    // obj->enQueue(11);

    // std::cout << "obj->isEmpty() " << obj->isEmpty() << std::endl;
    // std::cout << "obj->Front() " << obj->Front() << std::endl;
    // std::cout << "obj->Rear() " << obj->Rear() << std::endl;

    //["MyCircularQueue","enQueue","enQueue","Front","enQueue","deQueue","enQueue","enQueue","Rear","isEmpty","Front","deQueue"]
    //[[2],[8],[8],[],[4],[],[1],[1],[],[],[],[]]
    
    MyCircularQueue* obj = new MyCircularQueue(2);
    obj->enQueue(8);
    obj->enQueue(8);
    std::cout << "obj->Front() " << obj->Front() << std::endl;
    obj->enQueue(4);
    obj->deQueue();
    obj->enQueue(1);
    obj->enQueue(1);
    std::cout << "obj->Rear() " << obj->Rear() << std::endl;
    std::cout << "obj->isEmpty() " << obj->isEmpty() << std::endl;
    std::cout << "obj->Front() " << obj->Front() << std::endl;
    obj->deQueue();

    

    return 0;
}