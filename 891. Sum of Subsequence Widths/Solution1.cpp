// 891. Sum of Subsequence Widths
// Description:
// The width of a sequence is the difference between the maximum and minimum elements in the sequence.

// Given an array of integers nums, return the sum of the widths of all the non-empty subsequences of nums. 
// Since the answer may be very large, return it modulo 10^9 + 7.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 
// For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

// Example 1:
// Input: nums = [2,1,3]
// Output: 6
// Explanation: The subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
// The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
// The sum of these widths is 6.

// Example 2:
// Input: nums = [2]
// Output: 0

// Constraints:
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^5

// 1. Order does not matter, so first intuition is to sort the array.
// 2. Every number contribute based on its index in the sorted array
// For each number nums[i]:
// (1) There are i smaller numbers, so there are 2 ^ i sequences in which nums[i] is maximum.
// we should do res += nums[i] * 2^i
// (2) There are n - i - 1 bigger numbers, so there are 2 ^ (n - i - 1) sequences in which nums[i] is minimum.
// we should do res -= nums[i] * 2^(n - i - 1)
// Let n - i - 1 = j, i = n - 1 - j, so nums[i] * 2^(n - i - 1) = nums[n - 1 - j] * 2^j
// Therefore, for each nums[i], res += (nums[i] - nums[n - 1 - j]) * 2^i
// eg. nums= [1, 4, 5, 7], for i = 2
// nums[i] is maximum: [5], [1, 5], [4, 5], [1, 4, 5]. 2^2 = 4
// nums[i] is minimum: [5], [5, 7]. 2^(4 - 2 - 1) = 2

// Time Complexity: O(nlogn)
// Space Complexity: O(1)

#include <vector>
using std::vector;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const long mod = 1e9 + 7;
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        long res = 0;
        long p = 1;
        for (int i = 0; i < n; ++i) {
            res = (res + (nums[i] - nums[n - i - 1]) * p) % mod;
            p = (p << 1) % mod;
        }
        // In Cpp and Java, mod on negative number will still get a negative number.
        // so need to add mod and then divided by mod
        return (int)(res + mod) % mod;
    }
};