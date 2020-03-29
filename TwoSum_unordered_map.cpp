/*  29 Mar 2020
    ****** Two Sum ************
    Two Sum
    Solution
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].

    Input :
    nums = [3,3]  target = 6

    return [0,1]

    Fixed the problem using std::unordered_map
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> nums_map;

        std::vector<int> ret;
        int n,c;
        for(int i = 0 ; i < nums.size(); ++i)
        {
            n = nums.at(i);
            c = target - n;
            if(nums_map.find(c) != nums_map.end())
            {
                ret.emplace_back(nums_map[c]);
                ret.emplace_back(i);
                break;
            }
            nums_map[n] = i;
        }
        return ret;
    }
};

int main()
{
    std::vector<int> nums = {2, 5, 8, 7, 11, 15};
    Solution sol;
    int target = 9;
    std::vector<int> ans = sol.twoSum(nums, target);
    if(ans.size() > 0)
        cout<< "[" << ans.at(0) << ", " << ans.at(1) << "]" << endl;
    return 0;
}
