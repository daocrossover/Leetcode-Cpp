// Sorting Solution, but this method modifies the array
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

#include <vector>
using std::vector;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        return -1;
    }
};