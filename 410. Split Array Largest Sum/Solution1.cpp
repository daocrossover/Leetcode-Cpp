// Description:
// Given an array which consists of non-negative integers and an integer m,
// you can split the array into m non-empty continuous subarrays.
// Write an algorithm to minimize the largest sum among these m subarrays.

// Note:
// If n is the length of array, assume the following constraints are satisfied:
// 1 ≤ n ≤ 1000
// 1 ≤ m ≤ min(50, n)

// Examples:

// Input:
// nums = [7,2,5,10,8]
// m = 2
// Output:
// 18

// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.


// Dynamic Programming Solution:
// dp[i][j]: answer of spliting nums[0] to nums[j] into i groups
// dp[1][j]: sum(0, j)
// dp[i][j]: min{max(dp[i-1][k], sum(k+1, j))}  (0 <= k < j)
// Time Complexity: O(mn^2), Space Complexity: O(mn)

#include<vector>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(m+1, vector<int>(n, INT_MAX));
        vector<int> sum(n);
        sum[0] = nums[0];
        // calculate the sum
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i-1] + nums[i];
        }
        // initialization for group number = 1
        for (int j = 0; j < n; ++j) {
            dp[1][j] = sum[j];
        }
        
        for (int i = 2; i <= m; ++i) {
            // the array need to contain at least i element to be splited into i group
            for (int j = i - 1; j < n; ++j) {
                for (int k = 0; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], max(dp[i-1][k], sum[j] - sum[k]));
                }
            }
        }
        return dp[m][n-1];
    }
};