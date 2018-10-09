// Description:
// Given an integer array nums, find the contiguous subarray within an array (containing at least one number)
// which has the largest product.

// Example 1:
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


// Remember the max and min value for the previous product
// since a negative * negative could be positive.

#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int maxValue = nums[0], minValue = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int temp = maxValue;
            maxValue = max(max(maxValue * nums[i], minValue * nums[i]), nums[i]);
            minValue = min(min(temp * nums[i], minValue * nums[i]), nums[i]);
            if (maxValue > res) res = maxValue;
        }
        return res;
    }
};