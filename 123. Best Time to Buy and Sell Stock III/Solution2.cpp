// min is repeated calculated, so we could improved the Solution1
// Time Complexity: O(kn)
// Space Complexity: O(kn)

#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int K = 2, n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(K+1, vector<int>(n, 0));
        for (int k = 1; k <= K; ++k) {
            int min_value = prices[0];
            for (int i = 1; i < n; ++i) {
                min_value = min(min_value, prices[i] - dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i] - min_value);
            }
        }
        return dp[K][n-1];
    }
};