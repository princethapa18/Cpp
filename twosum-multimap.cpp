/* 4 Dec 2019 Two Sum Problem - solved using a std::multimap
  
  Given an array of integers, return indices of the two numbers such that they add up to a specific target
  You may assume that each input would have exactly one solution, and you may not use the same element twice.

  Example:
  Given nums = [2, 7, 11, 15], target = 9,

  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].

   3 Solutions 
   1. Brut force 
       vector<int> ret;
       for i = 0 to n-2 
	 for j = i+1 to n-1
	   if(arr[i] + arr[j] == target)
	     ret.push_back(i);  ret.push_back(j); 
	     return ret;
     time complexity = O(n^2) , space complexity O(1);
     
     first_num = arr[i]
     second_num = target - arr[i]   find this second_num
     
      If we use unordered_multimap  which is a hashtable which takes O(1) to find a key
   2. 2-pass hashtable   time complexity = O(n) + O(n) => O(n) , space complexity O(n);
   3. 1-pass hashtable   time complexity = O(n) , space complexity O(n);
   
   This program uses multimap which is a bst  which takes O(logn)  to find a key
   2-pass multimap time complexity = O(n) + O(nlogn) => O(n) , space complexity O(n);
   1-pass multimap time complexity = O(nlogn) , space complexity O(n);
   

	   
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        multimap<int, int> mp; // num , index
	vector<int> ret;
        /*  [3,2,4]  target = 6
            [3,3]    target = 6
            [3,2,1,2,4] target = 6  [1,4]
        */
        
        int s, i;
        //  1 pass hash map  12 ms
        multimap<int, int>::iterator itr;
        for(i = 0; i < nums.size() ; ++i)
        {
            s = target - nums.at(i);
            if( (itr = mp.find(s))!= mp.end() && itr->second != i )
            {            
                ret.push_back(itr->second);
                ret.push_back(i);
                return ret;
            }
            mp.insert(make_pair(nums.at(i), i));
        }
        
        /*
        // 2 pass hash map  (took 16 ms)
        // time complexity = O(n) + O(n)  = O(n)
        // space complexity = O(n)      extra space for hash map
        for(i = 0; i < nums.size() ; ++i)
        {
            mp.insert(make_pair(nums.at(i), i));
        }
        
        for(i = 0; i < nums.size() ; ++i)
        {
            f = nums.at(i);
            s = target - f;
            int count = mp.count(s);                           
            if(count > 1)
            {
                ret.push_back(i);
                pair<multimap<int, int>::iterator, multimap<int, int>::iterator > range =                                                                                                     mp.equal_range(s);
                 
                for(multimap<int, int>::iterator itr = range.first; itr!= range.second; ++itr)
                {
                    if(itr->second != i)
                    {
                        ret.push_back(itr->second);
                        break;
                    }
                }

                break;
            }
            else if(count == 1 && f!=s)
            {
                ret.push_back(i);
                multimap<int, int>::iterator itr = mp.find(s);
                ret.push_back(itr->second);
                break;
            }
                
        }
        */
        
        
        return ret;
    }
};

int main()
{
      //[3,2,1,2,4] target = 6  [1,4]
      vector<int> arr;
      arr.push_back(3);
      arr.push_back(2);
      arr.push_back(1);
      arr.push_back(2);
      arr.push_back(4);
      int target = 6;
      Solution sol;
      
      vector<int> ans = sol.twoSum(arr, target);
      
      if(ans.size() > 0)
	cout<< "[" << ans.at(0) << ", " << ans.at(1) << "]" << endl;
      
      
      return 0;
}

