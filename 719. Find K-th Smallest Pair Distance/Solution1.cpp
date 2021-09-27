// 719. Find K-th Smallest Pair Distance
// Description:
// The distance of a pair of integers a and b is defined as the absolute difference between a and b.
// Given an integer array nums and an integer k, 
// return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

// Example 1:
// Input: nums = [1,3,1], k = 1
// Output: 0
// Explanation: Here are all the pairs:
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// Then the 1st smallest distance pair is (1,1), and its distance is 0.

// Example 2:
// Input: nums = [1,1,1], k = 2
// Output: 0

// Example 3:
// Input: nums = [1,6,1], k = 3
// Output: 5

// Constraints:
// n == nums.length
// 2 <= n <= 10^4
// 0 <= nums[i] <= 10^6
// 1 <= k <= n * (n - 1) / 2

// Binary Search + Sliding Window
// Time Complexity: O(nlogn + nlogW), W = nums.back() - nums.front()
// Space Complexity: O(1)

#include <vector>
using std::vector;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // 1. sort the array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // 2. Binary Search, low = 0, high = max distance in the array
        // find the possible result which may be the k-th smallest distance among all the pairs
        int low = 0, high = nums.back() - nums.front();
        while (low < high) {
            int mid = low + (high - low) / 2;
            // 3. Sliding Window method to find the number of pairs which distances <= mid
            int count = 0;
            for (int right = 0, left = 0; right < n; ++right) {
                while (nums[right] - nums[left] > mid) {
                    left++;
                }
                count += right - left;
            }
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};