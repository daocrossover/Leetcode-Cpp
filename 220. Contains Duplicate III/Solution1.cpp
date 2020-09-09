// Description:
// Given an array of integers, find out whether there are two distinct indices i and j in the array such that 
// the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

// Example 1:
// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true

// Example 2:
// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true

// Example 3:
// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false

// Two Pointers with Set Solution:
// Time Complexity: O(nlogk)
// Space Complexity: O(k)

#include <vector>
#include <set>
using std::vector;
using std::set;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window;
        // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) window.erase(nums[i - k - 1]); // keep the set size at most k
            auto it = window.lower_bound((long long)nums[i] - t); // x-nums[i] >= -t -> x >= nums[i]-t
            if (it != window.end() && (*it - nums[i]) <= t) { // x - nums[i] <= t
                return true;
            }
            window.insert(nums[i]);
        }
        return false;
    }
};