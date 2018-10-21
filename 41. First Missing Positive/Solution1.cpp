// Description:
// Given an unsorted integer array, find the smallest missing positive integer.

// Example 1:
// Input: [1,2,0]
// Output: 3

// Example 2:
// Input: [3,4,-1,1]
// Output: 2

// Example 3:
// Input: [7,8,9,11,12]
// Output: 1
// Note:

// Your algorithm should run in O(n) time and uses constant extra space.


// Hashset Solution:
// Time Complexity: O(n), Space Complexity: O(n)
 
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        int maxNum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                s.insert(nums[i]);
                maxNum = max(maxNum, nums[i]);
            }
        }
        
        for (int i = 1; i <= maxNum; ++i) {
            if (!s.count(i)) return i;
        }
        return maxNum + 1;
    }
};