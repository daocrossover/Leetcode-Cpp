// 1043. Partition Array for Maximum Sum
// Description:
// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. 
// After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:
// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]

// Example 2:
// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83

// Example 3:
// Input: arr = [1], k = 1
// Output: 1

// Constraints:
// 1 <= arr.length <= 500
// 0 <= arr[i] <= 10^9
// 1 <= k <= arr.length

// Dynamic Progamming Solution:
// dp[i]: the maximum sum we can get considering A[0] ~ A[i-1]
// To get dp[i], we will try to change k last numbers separately to the maximum of them
// eg. Let arr = [9, 10, 2, 5] and k = 3
// Let S[n1, n2, ..., ni] be the solution to subarray [n1, n2, ..., ni].
// dp[1] = S[9] = 9
// dp[2] = S[9, 10] = 20
// dp[3] = S[9, 10, 2] = 30
// dp[4] = S[9, 10, 2, 5] = max(S[9] + S[10, 2, 5], S[9, 10] + S[2, 5], S[9, 10, 2] + S[5]) = 39
// we can reuse the result S[9], S[9, 10] and S[9, 10, 2]
// S[10, 2, 5] = max(10, 2, 5) * 3
// S[2, 5] = max(2, 5) * 2
// S[5] = max(5) * 1

// Time Complexity: O(nk)
// Space Complexity: O(n)

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int cur_max = 0, best = 0;
            for (int j = 1; j <= k && i - j >= 0; ++j) {
                cur_max = max(cur_max, arr[i - j]);
                best = max(best, dp[i - j] + cur_max * j);
            }
            dp[i] = best;
        }
        return dp[n];
    }
};