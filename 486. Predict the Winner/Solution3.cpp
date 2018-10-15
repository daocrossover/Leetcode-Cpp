// Minimax Solution + 2-D Dynamic Programming(bottom-up):
// dp[i][j]: store the maximum effective score possible for the subarray nums[i, j]
// dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1])
// the value for dp[0][n-1] gives the required result.
// Time Complexity: O(n^2) -> (n+1)*n/2
// Space Complexity: O(n^2)

#include<vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n));
        for (int s = n; s >= 0; --s) {
            for (int e = s + 1; e < n; ++e) {
                int a = nums[s] - dp[s + 1][e];
                int b = nums[e] - dp[s][e - 1];
                dp[s][e] = max(a, b);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};