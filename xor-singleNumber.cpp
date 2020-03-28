/* 28 Mar 2020
   *********** Single Number *************
    Given a non-empty array of integers, every element appears twice except for one. Find that single one.
    Note:
    Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
    Example 1:
    Input: [2,2,1]
    Output: 1

    Example 2:
    Input: [4,1,2,1,2]
    Output: 4
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        // xor
        // 0 | 0 | 0
        // 0 | 1 | 1
        // 1 | 1 | 0
        // x ^ x = 0   and 0 ^ y = 0
        // In this problem every element occurs twice except one.
        // Therefore taking xor of all the elements will give the answer
        // Ex: I/P  [4,1,2,1,2]
        // 4^1^2^1^2 = 4
        // Ex : 4^4   ==>   100
        //                  100
        //                  000
        for(int num: nums)
            ret = ret ^ num;
        return ret;
    }
};

int main()
{
    std::vector<int> vec = {4,2,2,1,3,1,3};
    Solution sln;
    int ret = sln.singleNumber(vec);
    cout << ret << endl;
}
