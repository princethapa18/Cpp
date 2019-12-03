/* 28 jan 2019
 heaptree
 heapifying an array into a max heap

 What is heap data structure?
 1. Complete binary tree [all levels must be full except the last level and child are added from left to right]
 2. Either a max heap [root is the maximum. parent is larger then its children] or min heap [ root is minimum. parent is lesser then its children]

  array can be used to create a heap tree
  we need to heapify the array
  If i  --> parent index
  then left child  = 2*i + 1   [or 2*i]    for 1 based index
       right child = 2*i + 2   [or 2*i+1]
  If i is the child index
     then parent  = (i - 1)/2  [or i/2]
*/

#include <stdio.h>
#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void printArray(int a[], int arrsize)
{
    for(int i = 0; i < arrsize; i++)
        cout << a[i] << " " ;
}

void max_heapify(int a[], int i, int arrsize)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int maxidx = i;
    if(l < arrsize && a[l] > a[i])
        maxidx = l;
    if(r < arrsize && a[r] > a[maxidx])
        maxidx = r;

    if(maxidx != i)
    {
        swap(a[maxidx], a[i]);
        max_heapify(a, maxidx, arrsize);
    }
}

void min_heapify(int a[], int i, int arrsize)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int minidx = i;
    if(l < arrsize && a[l] < a[i])
        minidx = l;
    if(r < arrsize && a[r] < a[minidx])
        minidx = r;

    if(minidx != i)
    {
        swap(a[minidx], a[i]);
        min_heapify(a, minidx, arrsize);
    }
}

/* bottom to top
   n --> no. of elements
   n/2 - 1 is index after which all other indexes are leaf nodes.
   therefore we don't have to heapify leaf nodes.
   Ex:
         2 (0)
        /    \
    10(1)     9(2)
    /  \      /
  5(3) 6(4) 1(5)

  n = 6
  i = n/2 - 1 = 2   [ indexes after 2 i.e 3, 4 and 5 are leaf nodes. Therefore no need to heapify them ]
*/

void heapify(int a[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
    {
        //max_heapify(a, i, n);
        min_heapify(a, i, n);
    }
}

int main()
{
    int a[] = {1, 9, 11, 3, 5, 7, 8, 21, 15};
    int n = 9;
    printArray(a, n);
    cout << "\nBuilding max heap ... " << endl;
    heapify(a, n);
    printArray(a, n);
    return 0;
}
