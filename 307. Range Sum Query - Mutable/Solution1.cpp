// 307. Range Sum Query - Mutable
// Description:
// Given an integer array nums, handle multiple queries of the following types:
// 1. Update the value of an element in nums.
// 2. Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

// Implement the NumArray class:
// NumArray(int[] nums) Initializes the object with the integer array nums.
// void update(int index, int val) Updates the value of nums[index] to be val.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

// Example 1:
// Input
// ["NumArray", "sumRange", "update", "sumRange"]
// [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// Output
// [null, 9, null, 8]
// Explanation
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1, 2, 5]
// numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

// Constraints:
// 1 <= nums.length <= 3 * 10^4
// -100 <= nums[i] <= 100
// 0 <= index < nums.length
// -100 <= val <= 100
// 0 <= left <= right < nums.length
// At most 3 * 10^4 calls will be made to update and sumRange.

// Segment Tree Solution:
// Array implementation, if the element at index i is not a leaf, its left and right child are stored at index 2i and 2i + 1 respectively.
// 1. Build segment tree
// We begin from the leaves, initialize them with input array elements a[0, 1, ... , n-1]
// Time Complexity: O(n)
// Space Complexity: O(2n) = O(n)
// 2. Update segment tree
// Time complexity: O(logn)
// Space Complexity: O(1)
// 3. Range Sum Query
// Time complexity: O(logn)
// Space Complexity: O(1)


#include <vector>
using std::vector;

class NumArray {
private:
    vector<int> tree;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(2 * n);
        for (int i = n, j = 0; i < 2 * n; ++i, ++j) {
            tree[i] = nums[j]; 
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }
    
    void update(int index, int val) {
        index += n;
        tree[index] = val;
        while (index > 0) {
            int left = index;
            int right = index;
            if (index % 2 == 0) {
                // index is left child
                right = index + 1;
            } else {
                // index is right child
                left = index - 1;
            }
            // parent is updated after child is updated
            tree[index / 2] = tree[left] + tree[right];
            index /= 2;
        }
    }
    
    int sumRange(int left, int right) {
        // get leaf with value 'left'
        left += n;
        // get leaf with value 'right'
        right += n;
        int sum = 0;
        while (left <= right) {
            // Check if 'left' is right child of its parent P
            if (left % 2 == 1) {
                // if 'left' is right child of its parent P, the P stores sum outside the range [left, right] so we don't need parent P sum. 
                // Add left to sum and set left to point to the right of P on the upper level.
                // (add 1 and divided by 2)

                // if 'left' is not right child of its parent P, set left to point to the P
                // will add parent sum in the future
                sum += tree[left];
                left++;
            }
            // Check if 'right' is left child of its parent P
            if (right % 2 == 0) {
                // if 'right' is left child of its parent P, the P stores sum outside the range [left, right] so we don't need parent P sum.
                // Add right to sum and set right to point to the left of P on the upper level.
                // (minus 1 and divided by 2)

                // if 'right' is not left child of its parent P, set right to point to the P
                // will add parent sum in the future
                sum += tree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */