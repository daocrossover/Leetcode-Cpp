// Divide and Conquer Solution:
// Split the array to two parts, the maxSubArray will exist in
// maxSubArray in left part or
// maxSubArray in right part or
// maxSubArray starting from right edge in left part + maxSubArray starting from left edge in right part

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSum(nums, 0, nums.size() - 1);
    }
    
    int maxSum(vector<int>& nums, int l, int h) {
        if (l == h) return nums[l];
        int m = l + (h - l) / 2;
        int left = maxSum(nums, l, m);
        int right = maxSum(nums, m + 1, h);
        int combine = findMax(nums, l, m, h);
        return max(max(left, right), combine);
    }
    
    int findMax(vector<int>& nums, int l, int m, int h) {
        int leftMax = INT_MIN, rightMax = INT_MIN;
        int sum = 0;
        for (int i = m; i >= l; --i) {
            sum += nums[i];
            leftMax = max(leftMax, sum);
        }
        sum = 0;
        for (int i = m + 1; i <= h; ++i) {
            sum += nums[i];
            rightMax = max(rightMax, sum);
        }
        return leftMax + rightMax;
    }
};