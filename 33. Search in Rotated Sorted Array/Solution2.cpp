#include<vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // find the target
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[low] <= nums[mid]) {
                // if the left half is in increasing order
                if (target >= nums[low] && target < nums[mid]) {
                    // if the target is in this half
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // if the right half is in increasing order
                if (target > nums[mid] && target <= nums[high]) {
                    // if the target is in this half
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};