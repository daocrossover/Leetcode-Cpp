// Dynamic Programming Solution:
// Time Complexity: O(n^2)
// Space Complexity: O(n)

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                int max1 = max(j, dp[j]);
                int max2 = max(i-j, dp[i-j]);
                dp[i] = max(dp[i], max1 * max2);
            }
        }
        return dp[n];
    }
};