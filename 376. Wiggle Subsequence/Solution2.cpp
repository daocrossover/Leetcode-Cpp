// Dynamic Programming Solution:

// Any element in the array could correspond to only one of the three possible states:
// 1. up position, it means nums[i] > nums[i−1]
// 2. down position, it means nums[i] < nums[i−1]
// 3. equals to position, nums[i] == nums[i−1]

// updating:
// 1. nums[i] > nums[i−1] -> up posiyion, the element before it must be a down position.
// Hence, up[i] = down[i-1] + 1 and the down[i] is the same as down[i-1]
// 2. nums[i] < nums[i−1] -> down posiyion, the element before it must be a up position.
// Hence, down[i] = up[i-1] + 1 and the up[i] is the same as up[i-1]
// 3. nums[i] == nums[i−1], up[i] and down[i] remains.

// In the end, we can find the larger out of up[length-1] and down[length-1] to find the max. 
// Time Complexity: O(n), Space Complexity: O(n)

#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> up(nums.size());
        vector<int> down(nums.size());
        up[0] = 1;
        down[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i-1]) {
                up[i] = down[i-1] + 1;
                down[i] = down[i-1];
            } else if (nums[i] < nums[i-1]) {
                down[i] = up[i-1] + 1;
                up[i] = up[i-1];
            } else {
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }
        return max(down[nums.size()-1], up[nums.size()-1]);
    }
};