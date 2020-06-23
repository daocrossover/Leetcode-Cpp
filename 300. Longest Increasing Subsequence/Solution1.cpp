// Description:
// Given an unsorted array of integers, find the length of longest increasing subsequence.

// Example:
// Input: [10,9,2,5,3,7,101,18]
// Output: 4 
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Note:
// There may be more than one LIS combination, it is only necessary for you to return the length.
// Your algorithm should run in O(n^2) complexity.
// Follow up: Could you improve it to O(nlogn) time complexity?

// Dynamic Programming Solution:
// dp[i] be the length of the LIS ending at index i such that nums[i] is the last element of the LIS.
// dp[i] = 1 + max(dp[j]) where 0 < j < i and arr[j] < arr[i]; or
// dp[i] = 1, if no such j exists.
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int max_len = 1;
        vector<int> dp(nums.size());
        dp[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            int max_val = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    max_val = max(max_val, dp[j]);
                }
            }
            dp[i] = max_val + 1;
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};