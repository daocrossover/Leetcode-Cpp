// Dynamic Programming Solution:
// Imporve space complexity
// Time Complexity: O(mn)
// Space Complexity: O(n)

#include<vector>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n+1, 0);
        int maxLen = 0, prev = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];
                if (matrix[i-1][j-1] == '1') {
                    dp[j] = min(dp[j-1], min(dp[j], prev)) + 1;
                    maxLen = max(maxLen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return maxLen * maxLen;
    }
};