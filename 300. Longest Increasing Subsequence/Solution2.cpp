// DP + Binary search
// Time Complexity: O(nlogn), Space Complexity: O(n)

#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (int i = 0; i < nums.size(); ++i) {
            int left = 0, right = dp.size();
            // find the first number in nums which is not less than nums[i]
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (dp[mid] < nums[i]) left = mid + 1;
                else right = mid;
            }
            // if not found, append the nums[i] in the back of dp
            if (right >= dp.size()) dp.push_back(nums[i]);
            // if found, replace the value in dp with nums[i]
            else dp[right] = nums[i];
        }
        return dp.size();
    }
};