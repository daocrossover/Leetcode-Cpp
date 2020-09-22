// Space Optimization:
// Time Complexity: O(klogn)
// Space Complexity: O(k)

#include <vector>
using std::vector;

class Solution {
public:
    int superEggDrop(int K, int N) {
		vector<int> dp(K + 1);
		int res = 0;
		for (; dp[K] < N; ++res) {
			for (int i = K; i > 0; --i) {
				dp[i] = dp[i] + dp[i - 1] + 1;
			}
		}
		return res;
    }
};