// Description:
// Given an array of integers nums sorted in ascending order,
// find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> targetRange{-1, -1};
        int leftIdx = extremeInsertionIndex(nums, target, true);
        // assert that leftIdx is within the array bounds and that target
        // is actually in nums.
        if (leftIdx == nums.size() || nums[leftIdx] != target) {
            return targetRange;
        }
        targetRange[0] = leftIdx;
        targetRange[1] = extremeInsertionIndex(nums, target, false) - 1;
        return targetRange;
    }
    
    int extremeInsertionIndex(vector<int>& nums, int target, bool left) {
        // returns leftmost (or rightmost) index at which target should be
        // inserted in sorted array nums via binary search.
        int lo = 0;
        int hi = nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            // if left is true, then we "recurse" on the left subarray on ties.
            // otherwise, we go right.
            if (nums[mid] > target || (left && target == nums[mid])) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};