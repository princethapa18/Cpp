//19 june 2019
#include <iostream>
using namespace std;

// naive or brute force solution . use 2 loops ---> count the no. of times an element occurs. remember which no. is already checked.
// takes O(n^2) time

// Better Solution bitwise operation : take a sum of xor. The no. occuring odd times will be the final result.   takes O(n)  time

int findOddOccuringNum(int arr[], int n)
{
    int ret = arr[0];
    for(int i = 1; i < n; i++)
      ret = ret ^ arr[i];
    return ret;
}

int main()
{
    int arr[] = {5, 6, 6, 3, 3, 4, 2, 5, 4};
    cout << findOddOccuringNum(arr, 9);
    return 0;
}