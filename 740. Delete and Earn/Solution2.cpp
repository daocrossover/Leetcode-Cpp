// The idea like House Robber 198
// Dynamic Programming Solution:
// dp[i]: maximum amount of money you can earn till position i
// dp[i] = max(dp[i-2] + nums[i], dp[i-1])
// And optimize space complexity to O(1)

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num: nums) {
            values[num] += num;
        }
        int prev1 = 0, prev2 = 0;
        for (int value: values) {
            int tmp = prev1;
            prev1 = max(prev2 + value, prev1);
            prev2 = tmp;
        }
        return prev1;
    }
};