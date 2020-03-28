/*  28 mar 2020
    ****** Intersection of 2 Arrays *********************
    Given two arrays, write a function to compute their intersection.
    Example 1:

    Input: nums1 = [1,2,2,1], nums2 = [2,2]
    Output: [2]

    Example 2:

    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    Output: [9,4]
    Note:

        Each element in the result must be unique.
        The result can be in any order.

*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> ret;
        std::unordered_set<int> s1;
        for(int num: nums1)
            s1.insert(num);

        for(int num: nums2)
        {
            if( (s1.find(num) != s1.end())  && (std::find(ret.begin(), ret.end(), num) == ret.end()) )
            {
                ret.emplace_back(num);
            }
        }
        return ret;
    }
    */

    vector<int> set_intersection(unordered_set<int>& set1, unordered_set<int>& set2)
    {
        vector<int> ret;
        for(int num: set1)
        {
            if(set2.find(num) != set2.end())
                ret.emplace_back(num);
        }
        return ret;
    }


    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> ret;
        std::unordered_set<int> s1, s2;
        for(int num: nums1)
            s1.insert(num);
        for(int num: nums2)
            s2.insert(num);

        if(s1.size() < s2.size())
            ret = set_intersection(s1, s2);
        else
            ret = set_intersection(s2, s1);
        return ret;
    }
};

int main()
{
    std::vector<int> nums1 = {4,9,5,3};
    std::vector<int> nums2 = {9,4,9,8,4};
    Solution sln;
    vector<int> intsn_nums = sln.intersection(nums1, nums2);
    for(int num: intsn_nums)
        cout << num << " ";
    return 0;
}



