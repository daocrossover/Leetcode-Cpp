// 688. Knight Probability in Chessboard
// Description:
// On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. 
// The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).
// A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, 
// then one cell in an orthogonal direction.

// Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.
// The knight continues moving until it has made exactly k moves or has moved off the chessboard.

// Return the probability that the knight remains on the board after it has stopped moving.

// Example 1:
// Input: n = 3, k = 2, row = 0, column = 0
// Output: 0.06250
// Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
// From each of those positions, there are also two moves that will keep the knight on the board.
// The total probability the knight stays on the board is 0.0625.

// Example 2:
// Input: n = 1, k = 0, row = 0, column = 0
// Output: 1.00000

// Constraints:
// 1 <= n <= 25
// 0 <= k <= 100
// 0 <= row, column <= n

// Time-homogeneous Markov chain with a finite state space:
// Let f[i][j][steps] be the probability of being on square (i, j) after steps steps. 
// Based on how a knight moves, we have the following recursion:
// f[r][c][steps] = ∑dr,dc f[r+dr][c+dc][steps−1] / 8.0
// Instead of using a three-dimensional array dp, use two two-dimensional ones dp and dp1, 
// storing the result of the two most recent layers we are working on. 
// dp1 will represent f[][][steps], and dp will represent f[][][steps-1].
// Time Complexity: O(n^2 * k)
// Space Complexity: O(n^2)

#include <vector>
using std::vector;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0));
        int dir[8][8] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
        dp[row][column] = 1;
        
        for (; k > 0; k--) {
            vector<vector<double>> dp1(n, vector<double>(n, 0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < 8; ++k) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];
                        if (r >= 0 && r < n && c >= 0 && c < n) {
                            dp1[r][c] += dp[i][j] / 8.0;
                        }
                    }
                }
            }
            dp = dp1;
        }
        double res = 0;
        for (auto &row : dp) {
            for (auto &x : row) {
                res += x;
            }
        }
        return res;
    }
};