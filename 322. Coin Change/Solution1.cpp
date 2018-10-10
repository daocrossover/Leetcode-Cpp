// Description:
// You are given coins of different denominations and a total amount of money amount.
// Write a function to compute the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:
// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1

// Example 2:
// Input: coins = [2], amount = 3
// Output: -1

// Note:
// You may assume that you have an infinite number of each kind of coin.

// Dynamic Programming Solution: bottom-up
// dp[i]: minimum number of coins needed to make change for amount i using coin denominations [C0,...,Cn-1]
// dp[i] = min(dp[i-Cj]) + 1 (0 <= j <= n-1)
// Time Complexity: O(S*n), Space Complexity: O(S)
// where S is the amount, n is denomination count.

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxLen = amount + 1;             
        vector<int> dp(maxLen, maxLen);  
        dp[0] = 0;   
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};