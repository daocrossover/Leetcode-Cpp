// Description:
// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// Example:
// Given nums = [-2, 0, 3, -5, 2, -1]
// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3

// Note:
// You may assume that the array does not change.
// There are many calls to sumRange function.


// Dynamic Programming Solution:
// sum[i]: sum of nums[k] (0 <= k <= i-1)
// sum[0] = 0;
// Time Complexity: O(1), Space Complexity: O(n)

#include<vector>
using namespace std;

class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int> nums) {
        sum.resize(nums.size() + 1);
        sum[0] = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            sum[i] = sum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */