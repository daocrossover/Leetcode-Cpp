// Description:
// Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

// Example 1:
// Input: nums = [1, 5, 1, 1, 6, 4]
// Output: One possible answer is [1, 4, 1, 5, 1, 6].

// Example 2:
// Input: nums = [1, 3, 2, 2, 3, 1]
// Output: One possible answer is [2, 3, 1, 3, 1, 2].

// Note:
// You may assume all input has valid answer.

// Follow Up:
// Can you do it in O(n) time and/or in-place with O(1) extra space?

// Small half:    4 . 3 . 2 . 1 . 0 .
// Large half:    . 9 . 8 . 7 . 6 . 5
// ----------------------------------
// Together:      4 9 3 8 2 7 1 6 0 5
// So write nums from the back, interweaving sorted[0..4] (indexed by j) and sorted[5..9] (indexed by k).

#include<vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());
        for (int i = nums.size() - 1, j = 0, k = i/2 + 1; i >= 0; --i) {
            if (i % 2 == 1) {
                nums[i] = copy[k++];
            } else {
                nums[i] = copy[j++];
            }
        }
    }
};