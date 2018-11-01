// Description:
// Given an array of integers nums and a positive integer k,
// find whether it's possible to divide this array into k non-empty subsets
// whose sums are all equal.

// Example 1:
// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// Output: True
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3)
// with equal sums.

// Note:
// 1 <= k <= len(nums) <= 16.
// 0 < nums[i] < 10000.


// DFS Solution:
// The same idea as Question 416

#include<vector>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) sum += nums[i];
        if (k <= 0 || sum % k != 0) return false;
        vector<bool> visited(nums.size());
        return canPartition(nums, visited, 0, k, 0, 0, sum / k);
    }

    // find a subset of nums[] which sum equals to sum/k.
    // Each time when we get a cur_sum = sum/k,
    // we will start from position 0 in nums[] to look up the elements
    // that are not used yet and find another cur_sum = sum/k.
    bool canPartition(vector<int>& nums, vector<bool>& visited, int start, int k, int cur_sum, int cur_num, int target){
        if (k == 1) return true;
        // An corner case is when sum = 0, method is to use cur_num
        // to record the number of elements in the current subset.
        if (cur_sum == target && cur_num > 0)
            return canPartition(nums, visited, 0, k-1, 0, 0, target);
        for (int i = start; i < nums.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                if (canPartition(nums, visited, i+1, k, cur_sum + nums[i], cur_num++, target))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
};
