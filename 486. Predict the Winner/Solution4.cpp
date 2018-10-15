// Minimax Solution + 1-D Dynamic Programming(bottom-up):
// dp[i][j]: store the maximum effective score possible for the subarray nums[i, j]
// dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1])
// Thus, for filling in any entry in dpdp array,
// only the entries in the next row(same column) and the previous column(same row) are needed.

// Instead of making use of a new row in dpdp array for the current dp row's updations,
// we can overwrite the values in the previous row itself and consider the values as belonging to the new row's entries,
// since the older values won't be needed ever in the future again.
// Thus, instead of making use of a 2-D dp array, we can make use of a 1-D dp array and make the updations appropriately.

// Time Complexity: O(n^2), Space Complexity: O(n)

#include<vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int s = n; s >= 0; --s) {
            for (int e = s + 1; e < n; ++e) {
                int a = nums[s] - dp[e];
                int b = nums[e] - dp[e - 1];
                dp[e] = max(a, b);
            }
        }
        return dp[n - 1] >= 0;
    }
};