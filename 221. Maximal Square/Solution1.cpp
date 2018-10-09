// Description:
// Given a 2D binary matrix filled with 0's and 1's, 
// find the largest square containing only 1's and return its area.

// Example:
// Input: 
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// Output: 4


#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0; // the max side length
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i] - '0';
            res = max(res, dp[0][i]);
        }
        for (int i = 1; i < m; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            res = max(res, dp[i][0]);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res * res;
    }
};