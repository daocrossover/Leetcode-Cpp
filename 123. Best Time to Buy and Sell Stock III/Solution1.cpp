// Description:
// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

// Example 1:
// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

// Example 2:
// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.

// Example 3:
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.


// Dynamic Programming Solution:
// dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j-1]), j=[0..i-1]
// For k transactions, on i-th day,
// 1. if we don't trade then the profit is same as previous day dp[k, i-1];
// 2. if we bought the share on j-th day where j=[0..i-1], then sell the share on i-th day
//    then the profit is prices[i] - prices[j] + dp[k-1, j-1].

// why the profit of second situatiob is not prices[i] - prices[j] + dp[k-1, j]?
// we can't buy the share and sell it on the same day!

// Time Complexity: O(kn), Space Complexity is O(kn).

#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        } else {
            int K = 2;
            int maxProfit = 0;
            vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
            for (int k = 1; k <= K; ++k) {
                int tmpMax = f[k-1][0] - prices[0];
                for (int i = 1; i < prices.size(); ++i) {
                    f[k][i] = max(f[k][i-1], prices[i] + tmpMax);
                    tmpMax = max(tmpMax, f[k-1][i] - prices[i]);
                    maxProfit = max(f[k][i], maxProfit);
                }
            }
            return maxProfit;
        }
    }
    
    // straigtforward implementation:
    // Time Complexity: O(kn^2), Space Complexity is O(kn).

    // int maxProfit(vector<int>& prices) {
    //     if (prices.size() <= 1) {
    //         return 0;
    //     } else {
    //         int K = 2;
    //         int maxProfit = 0;
    //         vector<vector<int>> dp(K+1, vector<int>(prices.size(), 0));
    //         for (int k = 1; k <= K; ++k) {
    //             for (int i = 1; i < prices.size(); i++) {
    //                 int minValue = prices[0];
    //                 for (int j = 1; j <= i; j++)
    //                     minValue = min(minValue, prices[j] - dp[k-1, j-1]);
    //                 dp[k, i] = max(dp[k, i-1], prices[i] - minValue);
    //             }
    //         }
    //         return maxProfit;
    //     } 
    // }
};