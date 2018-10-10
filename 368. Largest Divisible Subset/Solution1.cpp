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

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        vector<int> father(nums.size(), -1);
        vector<int> dp(nums.size(), 1);
        int index = -1, maxLen = 0;
        // sort the array first
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            // if nums[i] can be divided by nums[j],
            // it can also be divided by every element in dp[j].
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        // record the father of the i
                        father[i] = j;
                    }
                }
            }
            // record the max dp[i] and index i
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                index = i;
            }
        }
        while (index != -1) {
            res.push_back(nums[index]);
            index = father[index];
        }
        return res;
    }
};