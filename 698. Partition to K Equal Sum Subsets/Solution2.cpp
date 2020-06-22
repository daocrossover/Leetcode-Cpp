// Dynamic Programming with Bit Masking Solution:
// Let state have the i-th bit set if and only if nums[i] has already been used.
// Time Complexity: O(n * 2^n)
// Space Complexity: O(2^n)

#include <vector>
using std::vector;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        for (int num: nums) sum += num;
        int target = sum / k;
        if (sum % k != 0 || nums[n - 1] > target) return false;
        sort(nums.begin(), nums.end());
        vector<bool> dp(1 << n, false);
        dp[0] = true;
        vector<int> total(1 << n, 0);
        
        for (int state = 0; state < (1 << n); ++state) {
            if (!dp[state]) continue;
            for (int i = 0; i < n; ++i) {
                int next = state | (1 << i); // set the i-th bit
                if (state != next && !dp[next]) {
                    if (nums[i] <= target - total[state] % target) {
                        dp[next] = true;
                        total[next] = total[state] + nums[i];
                    } else {
                        break;
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};