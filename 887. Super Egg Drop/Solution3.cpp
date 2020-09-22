// Another Dynamic Programming Solution:
// dp[M][K] means that, given K eggs and M moves, what is the maximum number of floor that we can check.
// when we take 1 move to a floor,
// if egg breaks, then we can check dp[m - 1][k - 1] floors (downside check)
// if egg doesn't breaks, then we can check dp[m - 1][k] floors (upside check)
// Time Complexity: O(klogn)
// Space Complexity: O(kn)

#include <vector>
using std::vector;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k) {
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
            }  
        }
        return m;
    }
};