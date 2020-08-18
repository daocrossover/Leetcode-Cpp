// swap the two 'for' loops and improve space complexity
// Time Complexity: O(kn)
// Space Complexity: O(k)

#include <vector>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    /* swap the two 'for' loops
    int maxProfit(vector<int>& prices) {
        int K = 2, n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(K + 1, vector<int>(n, 0));
        vector<int> min_value(K + 1, prices[0]); // save min for each transaction
        for (int i = 1; i < n; ++i) {
            for (int k = 1; k <= K; ++k) {
                min_value[k] = min(min_value[k], prices[i] - dp[k-1][i-1]);
                dp[k][i] = max(dp[k][i-1], prices[i] - min_value[k]);
            }
        }
        return dp[K][n-1];
    } */
    
    // variable i is only dependent on the previous one (i-1), so we can compact this dimension.
    int maxProfit(vector<int>& prices) {
        int K = 2, n = prices.size();
        if (n <= 1) return 0;
        vector<int> dp(K + 1, 0), min_value(K + 1, prices[0]);
        for (int i = 1; i < n; ++i) {
            for (int k = 1; k <= K; ++k) {
                min_value[k] = min(min_value[k], prices[i] - dp[k-1]);
                dp[k] = max(dp[k], prices[i] - min_value[k]);
            }
        }
        return dp[K];
    }
};