// Greedy Solution:
// Keep a variable to store the current sum.
// If the sum is below zero, then we reset it to the current number (start from current number).

#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int curMax = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum >= 0) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            curMax = max(sum, curMax);
        }
        return curMax;
    }
};