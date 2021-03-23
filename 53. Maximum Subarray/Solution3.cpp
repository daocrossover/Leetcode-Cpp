// Greedy Solution:
// Keep a variable to store the current sum.
// If the sum is below zero, then we reset it to the current number (start from current number).
// Follow up:
// keep track of the starting and ending indices of the maximum subarray

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur_sum = 0, best_sum = INT_MIN;
        int best_start = 0, best_end = 0;
        int cur_start = 0;
        for (int cur_end = 0; cur_end < nums.size(); cur_end++) {
            if (cur_sum <= 0) {
                cur_start = cur_end;
                cur_sum = nums[cur_end];
            } else {
                cur_sum += nums[cur_end];
            }
            if (cur_sum > best_sum) {
                best_sum = cur_sum;
                best_start = cur_start;
                best_end = cur_end;
            }
        }
        return best_sum;
    }
};