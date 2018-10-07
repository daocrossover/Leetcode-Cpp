// Kadane's Algorithm
// the idea is same as DP
// Time Complexity: O(n), Space Complexity: O(1)

#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0], maxEndingHere = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);	
        }
        return maxSoFar;
    }
};