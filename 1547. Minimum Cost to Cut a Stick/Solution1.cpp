// 1547. Minimum Cost to Cut a Stick
// Description:
// Given a wooden stick of length n units. The stick is labelled from 0 to n.
// For example, a stick of length 6 is labelled as follows:
// [0, 1, 2, 3, 4, 5, 6]

// Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.
// You should perform the cuts in order, you can change the order of the cuts as you wish.

// The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. 
// When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). 
// Please refer to the first example for a better explanation.

// Return the minimum total cost of the cuts.

// Example 1:
// Input: n = 7, cuts = [1,3,4,5]
// Output: 16
// Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
// The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), 
// the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
// Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).

// Example 2:
// Input: n = 9, cuts = [5,6,1,4,2]
// Output: 22
// Explanation: If you try the given cuts ordering the cost will be 25.
// There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.

// Constraints:
// 2 <= n <= 10^6
// 1 <= cuts.length <= min(n - 1, 100)
// 1 <= cuts[i] <= n - 1
// All the integers in cuts array are distinct.

// Dynamic Programming
// Add the "cut" index 0 and n, then sort all stick position.
// dp[i][j]: the minimum cost to stick all sticks between A[i] and A[j]
// If j == i + 1 (len == 2), we can't cut on this stick, so dp[i][j] = 0.
// If j == i + 2 (len == 3), the only choice you have is to cut in the middle, and the cost is the length of this stick, 
// so dp[i][j] = A[i + 2] - A[i].
// If j > i + 2 (len >= 4), we can try to cut at k where i < k < j and use the minimum cost we can get 
// which is the cost of cutting the left part dp[i][k] plus the cost of cutting the right part dp[k][j] and the cost of the current cut A[j] - A[i], 
// so dp[i][j] = min(dp[i][k] + dp[k][j] + A[j] - A[i] | i < k < j)
// The answer is dp[0][N - 1]

#include <vector>
using std::vector;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int len = cuts.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len - 1; ++i) {
            dp[i][i + 1] = 0;
            if (i < len - 2) {
                dp[i][i + 2] = cuts[i + 2] - cuts[i];
            }
        }
        for (int i = len - 2; i >= 0; --i) {
            for (int j = i + 3; j < len; ++j) {
                int min_cut = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    min_cut = std::min(min_cut, dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
                dp[i][j] = min_cut;
            }
        }
        return dp[0][len - 1];
    }
};