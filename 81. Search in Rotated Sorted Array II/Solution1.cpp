// Description:
// Suppose an array sorted in ascending order is rotated at some pivot
// unknown to you beforehand.

// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

// You are given a target value to search. If found in the array return true,
// otherwise return false.

// Example 1:
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

// Example 2:
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false

// Follow up:
// This is a follow up problem to Search in Rotated Sorted Array,
// where nums may contain duplicates.
// Would this affect the run-time complexity? How and why?


// Binary Search:

#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // check if target == nums[mid], if so, we find it.
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                // deal with the tricky case
                low++;
                high--;
            } else if (nums[low] <= nums[mid]) {
                // if the first half is in order
                if (nums[low] <= target && nums[mid] > target) {
                    // target in the range of [low, mid-1], the first half
                    high = mid - 1;
                } else {
                    // target in the second half
                    low = mid + 1;
                }
            } else {
                // the second half is in order
                if (nums[mid] < target && nums[high] >= target) {
                    // target in the range of [mid+1, high], the second half
                    low = mid + 1;
                } else {
                    // target in the first half
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};