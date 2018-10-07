// Dynamic Programming Solution:
// When n = 0 or m =0 the function always returns 1 since the robot can't go left or up.
// For all other cells. The result = uniquePaths(m-1, n) + uniquePaths(m, n-1)

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};