// 2-D Dynamic Programming Solution:
// dp[i][j] refers to the number of assignments which can lead to a sum of j upto the i-th index 
// Time Complexity: O(n * sum), Space Complexity: O(n * sum)

#include<vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) sum += nums[i];
        if (sum < S || -sum > S) return 0;
        vector<vector<int>> dp(n, vector<int>(2*sum+1));
        dp[0][nums[0] + sum] += 1;
        dp[0][-nums[0] + sum] += 1;
        for (int i = 1; i < n; ++i) {
            for (int j = -sum; j <= sum; ++j) {
                if (dp[i-1][j + sum] != 0) {
                    dp[i][j + sum + nums[i]] += dp[i-1][j + sum];
                    dp[i][j + sum - nums[i]] += dp[i-1][j + sum];
                }
            }
        }
        return dp[n-1][S + sum];
    }
};