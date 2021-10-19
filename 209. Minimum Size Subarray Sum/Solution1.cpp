// 209. Minimum Size Subarray Sum
// Description:
// Given an array of positive integers nums and a positive integer target, 
// return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. 
// If there is no such subarray, return 0 instead.

// Example 1:
// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Example 2:
// Input: target = 4, nums = [1,4,4]
// Output: 1

// Example 3:
// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

// Constraints:
// 1 <= target <= 10^9
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^5

// Follow up: If you have figured out the O(n) solution, 
// try coding another solution of which the time complexity is O(nlog(n)).

// Sliding Window Problem:
// Two Pointers

#include <vector>
using std::vector;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX, cur_sum = 0;
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            cur_sum += nums[i];
            // use while instead of if
            while (cur_sum >= target) {
                min_len = std::min(min_len, i - j + 1);
                cur_sum -= nums[j];
                j++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};