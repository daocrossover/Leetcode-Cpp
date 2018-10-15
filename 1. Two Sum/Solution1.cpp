// Description:
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.

// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

// 1 pass Hashtable Solution:
// Time Complexity: O(n), Space Complexity: O(n)

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int rest = target - nums[i];
            if (hash.find(rest) != hash.end())
                return vector<int>{hash[rest], i};
            hash[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};