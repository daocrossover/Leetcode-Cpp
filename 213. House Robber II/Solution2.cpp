// The same idea as the Horse Robber I
// Compare two situation: nums[0, n-1] and nums[1, n]

#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        else if (nums.size() == 1) return nums[0];
        return max(robHelper(vector<int>(nums.begin()+1, nums.end())), robHelper(vector<int>(nums.begin(), nums.end()-1)));
    }
    
    int robHelper(vector<int> nums) {
        if (nums.size() == 0) return 0;
        int prev1 = 0;
        int prev2 = 0;
        for (int num : nums) {
            int tmp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = tmp;
        }
        return prev1;
    }
};