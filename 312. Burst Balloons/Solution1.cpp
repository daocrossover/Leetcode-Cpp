// Description:
// Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
// You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
// Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

// Find the maximum coins you can collect by bursting the balloons wisely.

// Note:
// You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
// 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

// Example:
// Input: [3,1,5,8]
// Output: 167 
// Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//              coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167


// Dynamic Programming Solution: bottom-up
// If the balloon i is burst in the end, we have already burst balloons [start, i–1] and [i+1, end].
// Hence, we can solve the problem in the following range:
// start – 1, solve(start, i – 1), i, solve(i + 1, end), end + 1
// dp[i][j]: the maximum coins we can get in balloons [i, j-1]

#include<vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> num; 
        num.push_back(1); // start – 1
        // assign numbers of array nums to a new array num
        for (int i = 0; i < nums.size(); ++i) {
            num.push_back(nums[i]);
        }
        num.push_back(1); // end + 1
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int dist = 2; dist < n; ++dist) {
            // try every distance from start to end
            for (int start = 0; start < n - dist; ++start) {
                int end = start + dist;
                // try every i between start and end
                for (int i = start + 1; i < end; ++i) {
                    dp[start][end] = max(dp[start][end], num[start] * num[i] * num[end] + dp[start][i] + dp[i][end]);
                }
            }
        }
        return dp[0][n-1];
    }
};