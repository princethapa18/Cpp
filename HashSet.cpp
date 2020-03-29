/*  29 Mar 2020   [ done earlier. committed on this date]
    ****** Design HashSet ***********
    Design a HashSet without using any built-in hash table libraries.

    To be specific, your design should include these functions:

    add(value): Insert a value into the HashSet.
    contains(value) : Return whether the value exists in the HashSet or not.
    remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

    Example:

    MyHashSet hashSet = new MyHashSet();
    hashSet.add(1);
    hashSet.add(2);
    hashSet.contains(1);    // returns true
    hashSet.contains(3);    // returns false (not found)
    hashSet.add(2);
    hashSet.contains(2);    // returns true
    hashSet.remove(2);
    hashSet.contains(2);    // returns false (already removed)

    Note:

    All values will be in the range of [0, 1000000].
    The number of operations will be in the range of [1, 10000].
    Please do not use the built-in HashSet library.

*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

const int TABLE_SIZE = 331;

class MyHashSet {
    std::vector<list<int> > m_bucketsList;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        m_bucketsList.resize(TABLE_SIZE);
    }

    int hashVal(int key) {
	    return (key % TABLE_SIZE);
    }

    void add(int key) {
        int idx = hashVal(key);
        if(find(m_bucketsList[idx].begin(), m_bucketsList[idx].end(), key) == m_bucketsList[idx].end())
            m_bucketsList[idx].push_front(key);
    }

    void remove(int key) {
        int idx = hashVal(key);
        std::list<int>::iterator it = find(m_bucketsList[idx].begin(), m_bucketsList[idx].end(), key); // if there is chaining
        if(it != m_bucketsList[idx].end())
            m_bucketsList[idx].erase(it);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = hashVal(key);
        if(find(m_bucketsList[idx].begin(), m_bucketsList[idx].end(),key) != m_bucketsList[idx].end())
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

 int main()
 {
    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    cout << "hashSet.contains(1) " << hashSet.contains(1) << endl;    // returns true
    cout << "hashSet.contains(3) " << hashSet.contains(3) << endl;    // returns false (not found)
    hashSet.add(2);
    cout << "hashSet.contains(2) " << hashSet.contains(2) << endl;    // returns true
    hashSet.remove(2);
    cout << "hashSet.contains(2) " << hashSet.contains(2) << endl;    // returns false (already removed)
    return 0;
 }

