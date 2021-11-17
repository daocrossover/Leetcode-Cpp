// 931. Minimum Falling Path Sum
// Description:
// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
// Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// Example 1:
// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown. ([1, 5, 7] and [1, 4, 8])

// Example 2:
// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown. ([-19, -40])

// Constraints:
// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100

// Dynamic Programming Solution:
// dp[i][j]: Minimum Path Sum until row i and col j
// dp[i][j] = matrix[i][j] + min(dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1])
// check the column 0 and n-1

#include <vector>
using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = matrix[i][j] + min(min(dp[i-1][j], dp[i-1][max(0, j-1)]), dp[i-1][min(n-1, j+1)]);
            }
        }
        int res = INT_MAX;
        for (int j = 0; j < n; ++j) {
            res = min(res, dp[n-1][j]);
        }
        return res;
    }
};