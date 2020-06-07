// 1-D Dynamic Programming Solution:
// Time Complexity: O(mn)
// Space Complexity: O(m)
// dp[i][j] only relys on dp[i][j-1] and dp[i-dj][j],
// so we could optimize the space by only using one-dimension array.

#include<vector>
using std::vector;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int coin: coins) {
            for (int j = coin; j <= amount; ++j) {
                dp[j] += dp[j-coin];
            }
        }
        return dp[amount];
    }
};