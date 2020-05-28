// Sorting Solution:
// Time complexity: O(nlogn)
// Space complexity: O(1)

#include<vector>
using std::vector;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};