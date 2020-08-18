// buy[i]: profit state after ith buy (hold)
// sell[i]: profit state after ith sell
// buy[i] = max(buy[i], sell[i-1] - price) // i-1th transaction sell and buy on current day
// sell[i] = max(sell[i], buy[i] + price) // ith transaction hold and sell on current day
// Time Complexity: O(kn)
// Space Complexity: O(k)

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        // if k >= n/2, then you can make maximum number of transactions.
        // the same situation in Best Time to Buy and Sell Stock II
        int max_profit = 0;
        if (k >= n / 2) {
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i-1]) {
                    max_profit += prices[i] - prices[i-1];
                }
            }
            return max_profit;
	    }
        // if k < n / 2, the same situation in Best Time to Buy and Sell Stock III Solution3
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int price: prices) {
            for (int i = 1; i <= k; ++i) {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
};