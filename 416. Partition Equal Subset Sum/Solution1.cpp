// Description:
// Given a non-empty array containing only positive integers,
// find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200.

// Example 1:
// Input: [1, 5, 11, 5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// Example 2:
// Input: [1, 2, 3, 5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.


// Dynamic Programming Solution:
// First, converting the problem to that: 
// Can we find a non-empty subset so that the sum of its elements is equal to target(sum/2)?

// For each nums[i], we need to update the dp[j] (nums[i] <= j <= target)
// for any number j, if dp[j-nums[i]] is true, then dp[j] must be true,
// so the state transition equation is as follows:
// dp[j] = dp[j] || dp[j - nums[i]] (nums[i] <= j <= target)

// Time Complexity: O(n*(sum/2)), Space Complexity: O(sum/2)

#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        // calculate the sum of array nums
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        // if sum is odd, array can't be partitioned into two subsets
        if (sum & 1) return false;
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = sum; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};