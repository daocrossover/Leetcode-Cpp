// Dynamic Programming Solution:
// Time Complexity: O(n^2), Space Complexity: O(n)
// My version:

#include<vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for (int i = 1; i <= n; ++i) {
            int maxProduct = 1;
            for (int j = 1; j < i; ++j) {
                int max1 = max(j, dp[j]);
                int max2 = max(i-j, dp[i-j]);
                maxProduct = max(maxProduct, max1 * max2);
            }
            dp[i] = maxProduct;
        }
        return dp[n];
    }
};