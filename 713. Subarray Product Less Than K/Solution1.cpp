// 713. Subarray Product Less Than K
// Description:
// Your are given an array of positive integers nums.
// Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

// Example 1:
// Input: nums = [10, 5, 2, 6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

// Note:
// 1. 0 < nums.length <= 50000
// 2. 0 < nums[i] < 1000
// 3. 0 <= k < 10^6

// Sliding Window Solution:
// Each step introduces x new subarrays, where x is the size of the current window (j + 1 - i);
// example:
// for window (5, 2), when 6 is introduced, it add 3 new subarray:
//       (6)
//    (2, 6)
// (5, 2, 6)

#include <vector>
using std::vector;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int left = 0, product = 1, count = 0;
        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right];
            while (left <= right && product >= k) {
                product /= nums[left++];
            }
            count += right - left + 1;
        }
        return count;
    }
};