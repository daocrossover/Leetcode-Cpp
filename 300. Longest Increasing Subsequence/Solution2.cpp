// DP + Binary search
// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <vector>
using std::vector;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); ++i) {
            int left = 0, right = dp.size();
            // find the first number in dp which is not less than nums[i]
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            if (right >= dp.size()) {
                // if not found, append the nums[i] in the back of dp
                dp.push_back(nums[i]);
            } else {
                // if found, replace the value in dp with nums[i]
                dp[right] = nums[i];
            }
        }
        return dp.size();
    }
};