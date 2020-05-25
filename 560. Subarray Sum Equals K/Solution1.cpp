// Description:
// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

// Example 1:
// Input:nums = [1,1,1], k = 2
// Output: 2
 
// Constraints:
// The length of the array is in range [1, 20,000].
// The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

// PreSum + HashMap solution
// if sum[i] - sum[j] = k, the sum of elements lying between indices i and j is k.
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<vector>
#include<unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSum;
        preSum[0] = 1;
        int sum = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (preSum.find(sum - k) != preSum.end()) {
                res += preSum[sum - k];
            }
            preSum[sum]++;
        }
        return res;
    }
};