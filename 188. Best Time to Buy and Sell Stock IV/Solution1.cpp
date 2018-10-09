// Description:
// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most k transactions.

// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

// Example 1:
// Input: [2,4,1], k = 2
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

// Example 2:
// Input: [3,2,6,5,0,3], k = 2
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
//              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.


#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int maxProfit = 0;
        if (k >= n / 2) {
            // if k >= n/2, then you can make maximum number of transactions.
            // the same situation in Best Time to Buy and Sell Stock II
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i-1])
                    maxProfit += prices[i] - prices[i-1];
            }
            return maxProfit;
	    }
        // if k < n / 2, the same situation in Best Time to Buy and Sell Stock III
        vector<vector<int>> f(k+1, vector<int>(prices.size(), 0));
        for (int j = 1; j <= k; ++j) {
            int tmpMax = f[j-1][0] - prices[0];
            for (int i = 1; i < prices.size(); ++i) {
                f[j][i] = max(f[j][i-1], prices[i] + tmpMax);
                tmpMax = max(tmpMax, f[j-1][i] - prices[i]);
                maxProfit = max(f[j][i], maxProfit);
            }
        }
        return maxProfit;
    }
};