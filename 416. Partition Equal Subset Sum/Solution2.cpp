// DFS Solution with Pruning

#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // sort the array and visit from the end, first visit the larger element
        sort(nums.begin(), nums.end());
        vector<int> sum(nums.size());
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] = sum[i-1] + nums[i];
        }
        int totalSum = sum[sum.size() - 1];
        if (totalSum & 1) return false;
        totalSum /= 2;
        return dfs(nums, sum, totalSum, nums.size() - 1);
        
    }
    
    bool dfs(vector<int>& nums, vector<int>& sum, int target, int index) {
        if (target == 0) return true;
        if (target < 0) return false;
        // visit from the end
        for (int i = index; i >= 0; --i) {
            if (sum[i] < target) {
                // if the sum of rest element is less than target, pruning 
                return false;
            } else if (sum[i] == target) {
                return true;
            } else{
                if (dfs(nums, sum, target - nums[i], i - 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};