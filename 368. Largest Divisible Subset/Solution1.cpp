// Description:
// Given a set of distinct positive integers,
// find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:
// Si % Sj = 0 or Sj % Si = 0.
// If there are multiple solutions, return any subset is fine.

// Example 1:
// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)

// Example 2:
// Input: [1,2,4,8]
// Output: [1,2,4,8]

// Dynamic Programming Solution:
// dp[i]: largest divisible subset size until position i
// parent[i]: record the position of last divisible number

#include<vector>
using std::vector;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        vector<int> dp(n, 1), parent(n, -1), res;
        int mx = 0, mx_idx = -1;
        // sort the array first
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            // if nums[i] can be divided by nums[j],
            // it can also be divided by every element in dp[j].
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    // record the father of the i
                    parent[i] = j;
                }
            }
            // record the max dp[i] and index i
            if (dp[i] > mx) {
                mx = dp[i];
                mx_idx = i;
            }
        }
        while (mx_idx != -1) {
            res.push_back(nums[mx_idx]);
            mx_idx = parent[mx_idx];
        }
        return res;
    }
};