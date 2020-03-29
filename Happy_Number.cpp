/*  29 Mar 2020
    ****** Happy Number ***************
    Write an algorithm to determine if a number is "happy".
    A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

    Example:
    Input: 19
    Output: true
    Explanation:
    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1

    Input: 3
    Output: false
    3^2 = 9
    9^2 = 81
    8^2 + 1^2 = 65
    6^2 + 5^2 = 81

    Because 81 is repeated it will go on an endless loop and 1 will never come.
    Therefore 3 is not a happy number.

    Input: 7
    Output: true
    7^2 = 49
    4^2 + 9^2 = 97
    9^2 + 7^2 = 130
    1^2 + 3^2 + 0^2 = 10
    1^2 + 0^2 = 1
    Thus 7 is a happy no.
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getSum(int n)
    {
        int sum = 0;
        while(n>0)
        {
            sum += (n%10)*(n%10);
            n = n/10;
        }

        return sum;
    }

    bool isHappy(int n) {
        std::unordered_set<int> s1;
        /* check till a sum is repeated or is equal to 1 */
        while(s1.find(n) == s1.end())
        {
            s1.insert(n);
            n = getSum(n);
            if(n==1)
                return true;
        }

        return false;
    }
};

int main()
{
    int n;
    cout << "Enter the input number: ";
    cin >> n;
    Solution sln;
    cout << "\nNumber " << n << " is " << (sln.isHappy(n) ? "" : "not ") << "happy" << endl;
    return 0;
}
