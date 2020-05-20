// Description:
// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Example:
// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Note:
// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.

// Two pointers solution improvement:
// All elements before the slow pointer (lastNonZeroFoundAt) are non-zeroes.
// All elements between the current and slow pointer are zeroes.
// Space Complexity : O(1)
// Time Complexity: O(n)
// The total operations (array writes) that code does is Number of non-0 elements.

#include<vector>
using std::vector;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // the index of last non-zero element
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums, i, j);
                j++;
            }
        }
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};