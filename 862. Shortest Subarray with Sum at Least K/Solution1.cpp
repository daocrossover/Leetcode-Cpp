// 862. Shortest Subarray with Sum at Least K
// Description:
// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. 
// If there is no such subarray, return -1. A subarray is a contiguous part of an array.

// Example 1:
// Input: nums = [1], k = 1
// Output: 1

// Example 2:
// Input: nums = [1,2], k = 4
// Output: -1

// Example 3:
// Input: nums = [2,-1,2], k = 3
// Output: 3

// Constraints:
// 1. 1 <= nums.length <= 10^5
// 2. -10^5 <= nums[i] <= 10^5
// 3. 1 <= k <= 10^9

// Follow-up question of LeetCode 209:
// Problem of the sliding window with negative values
// If we use the sliding window method of 209, it can not work.
// Example: nums = [3, -2, 5] and target = 4
// keep moving the end pointer, start=0 and end=2
// Now we are going to move the start pointer start=1. The sum of the current subarray is -2+5 < 4 so we violate the condition.
// However if we just move the start pointer another time start=2 we will find 5 >= 4 and we are satisfying the condition.
// Therefore, we can not use greedy idea here.

// Deque Solution - monotonic increasing queue:
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <queue>
using std::vector;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int res = n + 1;
        vector<int> sum(n + 1, 0);
        // calculate prefix sum array first, so we can get subarray sum in constant time later
        // sum[j] - sum[i] represents the sum of subarray nums[i] ~ nums[j-1]
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        // deque stores the possible values of the start pointer. 
        // Unlike the sliding window, values of the start variable will not necessarily be contiguous.
        std::deque<int> dq;
        // Basic idea, for array starting at every nums[i], find the shortest one with sum at least K.
        for (int i = 0; i <= n; ++i) {
            // keep checking if the front element of the queue satisfying the requirement
            // if it is, we can pop front, because there won't be any better solution in the future compared to (current - front), 
            // len of (future - front) is always larger
            while (!dq.empty() && sum[i] - sum[dq.front()] >= k) {
                res = std::min(res, i - dq.front());
                dq.pop_front();
            }
            // maintain a monotonic increasing queue
            // If sum[i] <= sum[dq.back()] and moreover we already know that i > dq.back()
            // compared with sum[dq.back()], sum[i] can help us make the subarray length shorter and sum bigger
            // sum[dq.back], sum[i], ... , sum[future id]
            // If sum[future id] - sum[dq.back()] >= k && sum[dq.back()] >= sum[i]
            // sum[future id] - sum[i] >= k too
            // So no need to keep dq.back() in our deque.
            while (!dq.empty() && sum[i] <= sum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res == n + 1 ? -1 : res;
    }
};