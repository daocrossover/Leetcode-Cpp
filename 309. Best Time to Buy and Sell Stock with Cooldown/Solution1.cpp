// Description:
// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit.
// You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

// Example:
// Input: [1,2,3,0,2]
// Output: 3 
// Explanation: transactions = [buy, sell, cooldown, buy, sell]


// State Machine Thinking:
// States transfer:
// s0--rest-->s0, s0--buy-->s1, s1--rest-->s1, s1--sell-->s2, s2--rest-->s0
// s0[i] = max(s0[i - 1], s2[i - 1]); // Stay at s0, or rest from s2
// s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]); // Stay at s1, or buy from s0
// s2[i] = s1[i - 1] + prices[i]; // Only one way from s1

// initial state:
// s0[0] = 0; At the start, you don't have any stock if you just rest
// s1[0] = -prices[0]; After buy, you should have -prices[0] profit. Be positive!
// s2[0] = INT_MIN; Lower base case

#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
		vector<int> s0(prices.size(), 0);
		vector<int> s1(prices.size(), 0);
		vector<int> s2(prices.size(), 0);
		s1[0] = -prices[0];
		s0[0] = 0;
		s2[0] = INT_MIN;
		for (int i = 1; i < prices.size(); i++) {
			s0[i] = max(s0[i - 1], s2[i - 1]);
			s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
			s2[i] = s1[i - 1] + prices[i];
		}
		return max(s0[prices.size() - 1], s2[prices.size() - 1]);
    }
};