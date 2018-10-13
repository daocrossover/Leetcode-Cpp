// Description:
// You are given coins of different denominations and a total amount of money.
// Write a function to compute the number of combinations that make up that amount.
// You may assume that you have infinite number of each kind of coin.

// Note: You can assume that
// 0 <= amount <= 5000
// 1 <= coin <= 5000
// the number of coins is less than 500
// the answer is guaranteed to fit into signed 32-bit integer
 
// Example 1:
// Input: amount = 5, coins = [1, 2, 5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
 
// Example 2:
// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
 
// Example 3:
// Input: amount = 10, coins = [10] 
// Output: 1


// Dynamic Programming Solution:
// d[i][j]: the number of ways to make change for amount i, using coin types d1,d2,...,dj
// choose dj or not
// dp[i][j] = dp[i][j-1] + dp[i-dj][j]
// Time Complexity: O(mn + nlogn), Space Complexity: O(mn)

#include<vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // sorting the denominations first
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1));
        for (int i = 1; i <= amount; ++i) dp[i][0] = 0;
        // if the amount == 0, the number of ways should be 1
        for (int j = 0; j <= coins.size(); ++j) dp[0][j] = 1;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 1; j <= coins.size(); ++j) {
                dp[i][j] = dp[i][j-1];
                if (i >= coins[j-1]) dp[i][j] += dp[i-coins[j-1]][j];
            }
        }
        return dp[amount][coins.size()];
    }
};