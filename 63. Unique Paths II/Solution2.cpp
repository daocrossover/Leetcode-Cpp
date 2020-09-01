// 1-D Dynamic Programming Solution:
// Time Complexity: O(mn)
// Space Complexity: O(n)
// dp[j] = dp[j] + dp[j - 1];
// new dp[j] = old dp[j] + dp[j-1]
// current cell = top cell + left cell

#include <vector>
using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (vector<int> row: obstacleGrid) {
            for (int j = 0; j < n; ++j) {
                if (row[j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};