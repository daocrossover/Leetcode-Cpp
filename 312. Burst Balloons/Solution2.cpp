// Dynamic Programming Solution: top-down

#include<vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
        return helper(nums, 0, nums.size() - 1, dp);
    }

    int helper(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if (start > end) return 0;
        if (dp[start][end] != 0) return dp[start][end];
        int maxCoin = nums[start];
        for (int i = start; i <= end; i++) {
            int val = helper(nums, start, i - 1, dp) + 
                    get(nums, i) * get(nums, start - 1) * get(nums, end + 1) + 
                    helper(nums, i + 1, end, dp);
            maxCoin = max(maxCoin, val);
        }
        dp[start][end] = maxCoin;
        return maxCoin;
    }

    int get(vector<int>& nums, int i) {
        if (i == -1 || i == nums.size()) {
            return 1;
        }
        return nums[i];
    }
};