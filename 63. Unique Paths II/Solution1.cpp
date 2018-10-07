// Description:
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// Note: m and n will be at most 100.

// Example 1:
// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right


// Dynamic Programming Solution:

#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0; 
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        int dp[n][m];
        // the first colomn in the grid
        for (int i = 0; i < n; i++) {
            // if encounter the obstacle
            if (obstacleGrid[i][0] == 1) {
                // the rest cell can't reach the goal
                while (i < n) {
                    dp[i][0] = 0;
                    i++;
                }
            } else {
                dp[i][0] = 1;
            }
        }
        // the first row in the grid
        for (int j = 0; j < m; j++) {
            // if encounter the obstacle
            if (obstacleGrid[0][j] == 1) {
                // the rest cell can't reach the goal
                while (j < m) {
                    dp[0][j] = 0;
                    j++;
                }
            } else {
                dp[0][j] = 1;
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else dp[i][j] = 0;
            }
        }
        return dp[n-1][m-1];
    }
};