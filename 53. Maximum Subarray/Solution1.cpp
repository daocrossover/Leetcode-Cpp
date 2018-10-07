// Description:
// Given an integer array nums, find the contiguous subarray (containing at least one number)
// which has the largest sum and return its sum.

// Example:
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// Follow up:
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


// Dynamic Programming Solution:
// dp[i]: the maxSubArray for nums[0:i] which must has nums[i] as the end element.
// dp[i] = (dp[i-1] > 0 ? dp[i-1] : 0) + nums[i]
// Time Complexity: O(n), Space Complexity: O(n)

#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxSum = dp[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = (dp[i-1] > 0 ? dp[i-1] : 0) + nums[i];
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};