// Description:
// Given an array nums of n integers and an integer target,
// are there elements a, b, c, and d in nums such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.

// Note:
// The solution set must not contain duplicate quadruplets.

// Example:
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i) {
            // prunning when the first element is too large
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            // first element is too small
            if (nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip same result
            for (int j = i + 1; j < n - 2; ++j) {
                // prunning when the second element is too large
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                // second element is too small
                if (nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) continue;
                if (j > i + 1 && nums[j] == nums[j-1]) continue; // skip same result
                int k = j + 1, m = n - 1;
                while (k < m) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[m];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[m]});
                        k++;
                        m--;
                        while (k < m && nums[k] == nums[k-1]) k++; // skip same result
                        while (k < m && nums[m] == nums[m+1]) m--; // skip same result
                    } else if (sum > target) {
                        m--;
                    } else {
                        k++;
                    }
                }
            }
        }
        return res;
    }
};