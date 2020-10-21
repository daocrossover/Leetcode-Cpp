// 1223. Dice Roll Simulation
// Description:
// A die simulator generates a random number from 1 to 6 for each roll. 
// You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times. 
// Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls.
// Two sequences are considered different if at least one element differs from each other. Since the answer may be too large, return it modulo 10^9 + 7.

// Example 1:
// Input: n = 2, rollMax = [1,1,2,2,2,3]
// Output: 34
// Explanation: There will be 2 rolls of die, if there are no constraints on the die, there are 6 * 6 = 36 possible combinations. 
// In this case, looking at rollMax array, the numbers 1 and 2 appear at most once consecutively, 
// therefore sequences (1,1) and (2,2) cannot occur, so the final answer is 36-2 = 34.

// Example 2:
// Input: n = 2, rollMax = [1,1,1,1,1,1]
// Output: 30

// Example 3:
// Input: n = 3, rollMax = [1,1,1,2,2,3]
// Output: 181

// Constraints:
// 1. 1 <= n <= 5000
// 2. rollMax.length == 6
// 3. 1 <= rollMax[i] <= 15

// Dynamic Programming Solution:
// dp[i][j]: how many combinations it could be that at i-th rolling and the last face is j
// sum[i]: how many combinations it could be that at i-th rolling in total
// if i = 5, last face j = 5 and rollMax[j] = 3
// if there is no restriction, sequence xxxx5 and x is in [0, 5]
// when one consecutive 5 - xxxy5, y is in [0, 4] and have sum[i-1] - dp[i-1][5] combinations
// when two consecutive 5 - xxy55, y is in [0, 4] and have sum[i-2] - dp[i-2][5] combinations
// when three consecutive 5 - xy555, y is in [0, 4] and have sum[i-3] - dp[i-3][5] combinations

#include <vector>
using std::vector;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        long p = 1e9 + 7;
        vector<vector<long>> dp(n + 1, vector<long>(6, 0));
        vector<long> sum(n + 1, 0);
        // initialization
        // roll 0 times, the total combination is 1
        sum[0] = 1;
        // roll 1 times, the combinations that end at face j is 1
        for (int j = 0; j < 6; ++j) {
            dp[1][j] = 1;
        }
        // roll 1 times, the total combination is faces = 6
        sum[1] = 6;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 6; ++j) {
                for (int k = 1; k <= rollMax[j] && i - k >= 0; ++k) {
                    dp[i][j] += (sum[i-k] - dp[i-k][j] + p) % p;
                }
                sum[i] = (sum[i] + dp[i][j]) % p;
            }
        }
        return sum[n];
    }
};