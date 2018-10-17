// Description:
// Given an array nums of n integers and an integer target,
// find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.

// Example:
// Given array nums = [-1, 2, 1, -4], and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


// Two Pointers Solution:
// Sort the array, iterate through the list,
// and use another two pointers to approach the target.

#include<vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0, diff = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int curDiff = abs(sum - target);
                if (sum == target) {
                    return sum;
                }
                if (curDiff < diff) {
                    diff = curDiff;
                    res = sum;
                }
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return res;
    }
};