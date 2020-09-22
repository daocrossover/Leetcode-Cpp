// Optimization:
// As for a fixed k, dp[i][k] goes up as k increases. 
// This means dp[i-1][k-1] will increase and dp[i][j-k] will decrease as k goes from 1 to j.
// The optimal value of k will be the middle point where the two meet.
// Also, we can see that the optimal floor k for each dp[i][j] increases as j increases. 
// This means that once we get the optimal k for dp[i][j], we can save current k value and start the next round of for-loop directly, instead of initiating k from 0 again.
// Time Complexity: O(kn)
// Space Complexity: O(kn)

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
            int s = 1;
            for (int j = 2; j <= N; ++j) {
                dp[i][j] = j;
                while (s < j && dp[i - 1][s - 1] < dp[i][j - s]) ++s;
				dp[i][j] = min(dp[i][j], dp[i - 1][s - 1] + 1);
            }
        }
        return dp[K][N];
    }
};