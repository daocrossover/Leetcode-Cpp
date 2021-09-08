// 238. Product of Array Except Self
// Description:
// Given an integer array nums, return an array answer such that 
// answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 
// Constraints:
// 1. 2 <= nums.length <= 10^5
// 2. -30 <= nums[i] <= 30
// 3. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// Follow up: Can you solve the problem in O(1) extra space complexity? 
// (The output array does not count as extra space for space complexity analysis.)

// Left and Right product lists solution:
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        vector<int> left(n, 1); // left[i] already contains the product of elements to the left of i
        vector<int> right(n, 1); // right[i] already contains the product of elements to the right of i
        for (int i = 1; i < n; ++i) {
            left[i] = left[i-1] * nums[i-1];
        }
        for (int i = n - 2; i >= 0; --i) {
            right[i] = right[i+1] * nums[i+1];
        }
        // constructing the answer array
        for (int i = 0; i < n; i++) {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};