// 740. Delete and Earn
// Description:
// Given an array nums of integers, you can perform operations on the array.
// In each operation, you pick any nums[i] and delete it to earn nums[i] points. 
// After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

// You start with 0 points. Return the maximum number of points you can earn by applying such operations.

// Example 1:
// Input: nums = [3, 4, 2]
// Output: 6
// Explanation: 
// Delete 4 to earn 4 points, consequently 3 is also deleted.
// Then, delete 2 to earn 2 points. 6 total points are earned.

// Example 2:
// Input: nums = [2, 2, 3, 3, 3, 4]
// Output: 9
// Explanation: 
// Delete 3 to earn 3 points, deleting both 2's and the 4.
// Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
// 9 total points are earned.

// Note:
// The length of nums is at most 20000.
// Each element nums[i] is an integer in the range [1, 10000].

// Dynamic Programming + Bucket
// For first (i+1) buckets from 0 to i
// take[i]: best earning if you skipped the (i-1)th bucket, and you take bucket[i]
// skip[i]: best earning if you skipped the i-th bucket, either take[i-1] or skip[i-1], whatever the bigger
// take[i] = skip[i-1] + values[i]
// skip[i] = Math.max(skip[i-1], take[i-1])
// Since the take and skip only depends on the previous value, we could reduce to O(1) space complexity for dp part
// Time Complexity: O(10001)
// Space Complexity: O(10001)

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        // if you earn values[i], you cannot earn values[i-1] and values[i+1]
        for (int num: nums) {
            values[num] += num;
        }
        int take = 0, skip = 0; // take and skip to replace take[i] and skip[i]
        for (int value: values) {
            int take_i = skip + value;
            int skip_i = max(skip, take);
            take = take_i;
            skip = skip_i;
        }
        return max(take, skip);
    }
};