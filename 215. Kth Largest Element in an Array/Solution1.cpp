// 215. Kth Largest Element in an Array
// Description:
// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Example 1:
// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

// Example 2:
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

// Constraints:
// 1 <= k <= nums.length <= 10^4
// -10^4 <= nums[i] <= 10^4

// Min Heap Solution:
// Time Complexity: O(nlogk)
// Space Complexity: O(k)

#include <vector>
#include <queue>
using std::priority_queue;
using std::vector;
using std::greater;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) {
                q.push(nums[i]);
            } else {
                if (nums[i] > q.top()) {
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
        // Or
        // for (int n: nums) {
        //     pq.push(n);
        //     if (pq.size() > k) {
        //         pq.pop();
        //     }
        // }
        return q.top();
    }
};