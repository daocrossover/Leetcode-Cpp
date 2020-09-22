// Description:
// You are given K eggs, and you have access to a building with N floors from 1 to N. 
// Each egg is identical in function, and if an egg breaks, you cannot drop it again.
// You know that there exists a floor F with 0 <= F <= N such that any egg dropped at a floor higher than F will break, and any egg dropped at or below floor F will not break.
// Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= N). 
// Your goal is to know with certainty what the value of F is.
// What is the minimum number of moves that you need to know with certainty what F is, regardless of the initial value of F?

// Example 1:
// Input: K = 1, N = 2
// Output: 2
// Explanation: 
// Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
// Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
// If it didn't break, then we know with certainty F = 2.
// Hence, we needed 2 moves in the worst case to know what F is with certainty.

// Example 2:
// Input: K = 2, N = 6
// Output: 3

// Example 3:
// Input: K = 3, N = 14
// Output: 4
 
// Note:
// 1. 1 <= K <= 100
// 2. 1 <= N <= 10000

// Brute-force Solution:
// 2-D Dynamic Programming
// dp[i][j]: smallest number of drop to get the optimal floor with i eggs and j floors left.
// dp[1][j] = j, j = 1...N: one egg, check each floor from 1 to j
// dp[i][0] = 0, i = 1...K: no floor, no drop needed to get the optimal floor
// dp[i][1] = 1, i = 1...K: one floor, only check once
// dp[i][j] = min(1 + max(dp[i-1][k-1], dp[i][j-k])), k = 1,2,...j
// Time Complexity: O(kn^2)
// Space Complexity: O(kn)
// Time Limit Exceeded

#include <vector>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        for (int i = 1; i <= K; ++i) {
            dp[i][1] = 1;
            dp[i][0] = 0;
        }
        for (int j = 1; j <= N; ++j) {
            dp[1][j] = j;
        }
        for (int i = 2; i <= K; ++i) {
            for (int j = 2; j <= N; ++j) {
                dp[i][j] = j;
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], max(dp[i-1][k-1], dp[i][j-k]) + 1);
                }
            }
        }
        return dp[K][N];
    }
};