// 259. 3Sum Smaller
// Description:
// Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n 
// that satisfy the condition nums[i] + nums[j] + nums[k] < target.

// Example:
// Input: nums = [-2,0,1,3], and target = 2
// Output: 2 
// Explanation: Because there are two triplets which sums are less than 2:
//              [-2,0,1]
//              [-2,0,3]

// Follow up: Could you solve it in O(n^2) runtime?

// Two Pointer Solution:
// Time Complexity: O(n^2)

#include <vector>
using std::vector;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    // everything between second and third element also meets condition
                    res += right - left;
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};