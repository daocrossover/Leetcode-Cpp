// Dynamic Programming Solution: top-down
// F(S): minimum number of coins needed to make change for amount S using coin denominations [C0,...,Cn-1]
// F(S) = min(F(S-Cj)) + 1 (0 <= j <= n-1) subject to S-Cj >= 0
// F(S) = 0, when S = 0;
// F(S) = -1, when n = 0;
// Time Complexity: O(S*n), Space Complexity: O(S)
// where S is the amount, n is denomination count.


#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) return 0;
        vector<int> dp(amount);
        return coinChangeHelper(coins, amount, dp);
    }
    
    int coinChangeHelper(vector<int>& coins, int rem, vector<int>& dp) {
        if (rem < 0) return -1;
        if (rem == 0) return 0;
        if (dp[rem - 1] != 0) return dp[rem - 1];
        int minNum = INT_MAX;
        for (int coin : coins) {
            int res = coinChangeHelper(coins, rem - coin, dp);
            if (res >= 0 && res < minNum)
                minNum = 1 + res;
        }
        dp[rem - 1] = (minNum == INT_MAX) ? -1 : minNum;
        return dp[rem - 1];
    }
};