// 1-D Dynamic Programming Solution:
// Maintaining a column is enough
// dp[i] = min(dp[i-1], dp[i]) + grid[i][j]
// dp[i] will be the top row and dp[i-1] will be the left column 
// Time Complexity: O(mn)
// Space Complexity: O(m)

#include <vector>
#include <algorithm>
using std::vector;
using std::min;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(m, 0);
        dp[0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i] = dp[i-1] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0] += grid[0][j];
            for (int i = 1; i < m; ++i) {
                dp[i] = min(dp[i-1], dp[i]) + grid[i][j];
            }
        }
        return dp[m-1];
    }
};