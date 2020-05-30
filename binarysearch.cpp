// 30 may 2020
#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    int searchIn(int l, int h, vector<int>& nums, int target)
    {
        if(l <= h)
        {
            int mid = (l+h)/2;       
            if( target == nums.at(mid) )
                return mid;
            else if(target > nums.at(mid))
            {
                l = mid + 1;
                return searchIn(l, h, nums, target);
            }
            else if(target < nums.at(mid))
            {
                h = mid - 1;
                return searchIn(l, h, nums, target);
            }       
        }    
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) 
    {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1)
        {
            if(nums.at(0) == target)
                return 0;
            else 
                return -1;
        }
        
        int ret = searchIn(0, nums.size()-1, nums, target);
        return ret;
    }
};


int main()
{
    //Input: nums = [-1,0,3,5,9,12], target = 9
    // Output: 4
    // Explanation: 9 exists in nums and its index is 4

    //Input: nums = [-1,0,3,5,9,12], target = 2
    //Output: -1
    //Explanation: 2 does not exist in nums so return -1
    std::vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;

    Solution obj;
    cout << "O/P : " << obj.search(nums, target) << endl;

    return 0;
}