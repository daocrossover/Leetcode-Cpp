// 977. Squares of a Sorted Array
// Description:
// Given an integer array nums sorted in non-decreasing order, 
// return an array of the squares of each number sorted in non-decreasing order.

// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

// Example 2:
// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

// Constraints:
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.

// Two Pointers Solution:

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // move from right to left in res, no need to reverse the array
        int i = 0, j = nums.size() - 1, k = nums.size() - 1;
        vector<int> res(nums.size());
        while (i <= j) {
            if (abs(nums[j]) > abs(nums[i])) {
                res[k] = nums[j] * nums[j];
                j--;
            } else {
                res[k] = nums[i] * nums[i];
                i++;
            }
            k--;
        }
        return res;
    }
};