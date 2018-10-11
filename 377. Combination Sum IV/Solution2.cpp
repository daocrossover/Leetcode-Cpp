// Dynamic Programming Solution: top-down

#include<vector>
using namespace std;

class Solution {
    vector<int> dp;
public:
    int combinationSum4(vector<int>& nums, int target) {
        int count = 0;
        dp.resize(target+1, -1);
        dp[0] = 1;
        return dfs(nums, target);
    }
    
    int dfs(vector<int>& nums, int target) {
        if (dp[target] != -1) return dp[target];
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= target) {
                res += dfs(nums, target - nums[i]);
            }
        }
        dp[target] = res;
        return res;
    }
};