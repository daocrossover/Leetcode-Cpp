// Space-Optimized Dynamic Programming Solution:
// The idea is same as the Solution2
// For updating elements up[i] and down[i], we need only the elements up[i-1] and down[i-1].
// Thus, we can save space by not using the whole array, but only the last elements.
// Time Complexity: O(n), Space Complexity: O(1)

#include<vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n);
        dp[0] = 1;
        int up = 1, down = 1;
        // up: maxLength of wiggle sequence with a up ending
        // down: maxLength of wiggle sequence with a down ending
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) up = down + 1;
            else if (nums[i] < nums[i-1]) down = up + 1;
        }
        return max(up, down);
    }
};