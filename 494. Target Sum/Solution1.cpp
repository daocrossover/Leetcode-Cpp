// Description:
// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S.
// Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

// Find out how many ways to assign symbols to make sum of integers equal to target S.

// Example 1:
// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 
// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3
// There are 5 ways to assign symbols to make the sum of nums be target 3.

// Note:
// The length of the given array is positive and will not exceed 20.
// The sum of elements in the given array will not exceed 1000.
// Your output answer is guaranteed to be fitted in a 32-bit integer.


// 1-D Dynamic Programming Solution:
// Time Complexity: O(n * sum), Space Complexity: O(sum)

#include<vector>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        // calculate the totalSum keeping all the elements in the array positive
        for (int i = 0; i < nums.size(); ++i) sum += nums[i];
        // if the target sum S is not reachable by the range
        if (sum < S || -sum > S) return 0;
        // dp[i]: the number of ways to have sum = i - totalSum
        vector<int> dp(2 * sum + 1);
        // start from no elements in the array, so there is one way to have sum = 0 that there is no element
        dp[0 + sum] = 1;
        // start from deciding to add the first element as positive or negative
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> next(2 * sum + 1);
            for (int j = 0; j < 2 * sum + 1; ++j) {
                // if current sum j - totalSum is already reached by the previous searched numbers
                if (dp[j] != 0) {
                    next[j + nums[i]] += dp[j];
                    next[j - nums[i]] += dp[j];
                }
            }
            dp = next;
        }
        return dp[S + sum];
    }
};