// Description:
// Implement next permutation,
// which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such arrangement is not possible,
// it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place and use only constant extra memory.

// Here are some examples.
// Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1


#include<vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // start from the end of the array, find the first element
        // that is not in the increasing order
        while (i >= 0 && nums[i+1] <= nums[i]) {
            i--;
        }
        // the subarray behind i is in non-increasing order
        if (i >= 0) {
            int j = nums.size() - 1;
            // find the element nums[j] just larger than nums[i]
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // swap them
            swap(nums[i], nums[j]);
        }
        // reverse the subarray
        // the whole array is in non-increasing order, i = -1, hence reverse the whole array
        reverse(nums, i + 1);
    }
    
    void reverse(vector<int>& nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};