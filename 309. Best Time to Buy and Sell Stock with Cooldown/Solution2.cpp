// Dynamic Programming Solution:
// buy[i]: max profit till index i for any sequence end with buy.
// sell[i]: max profit till index i for any sequence end with sell.
// rest[i]: max profit till index i for any sequence end with rest.

// Then we want to deduce the transition functions for buy sell and rest.
// By definition we have:
// buy[i]  = max(rest[i-1]-price, buy[i-1]) -> we have to rest before we buy 
// sell[i] = max(buy[i-1]+price, sell[i-1]) -> we have to buy before we sell
// rest[i] = max(sell[i-1], buy[i-1], rest[i-1])
// Where price is the price of day i.

// Hence, we can conclude that
// (1) buy[i] <= rest[i] -> rest[i] = max(sell[i-1], rest[i-1]) and [buy, rest, buy] is never occurred.
// (2) rest[i] <= sell[i] -> rest[i] = sell[i-1]

// Then the transition functions could be turned to:
// buy[i] = max(sell[i-2]-price, buy[i-1])
// sell[i] = max(buy[i-1]+price, sell[i-1])

// Optimize to O(1) Space
// Let b1, b0 represent buy[i-1], buy[i]
// Let s2, s1, s0 represent sell[i-2], sell[i-1], sell[i]
// b0 = max(s2-price, b1)
// s0 = max(b1+price, s1)

#include <vector>
using std::vector;
using std::max;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int b0 = -prices[0], b1 = b0;
        int s0 = 0, s1 = 0, s2 = 0;
        for (int price : prices) {
            b0 = max(s2 - price, b1);
            s0 = max(b1 + price, s1);
            b1 = b0;
            s2 = s1;
            s1 = s0;
        }
        return s0;
    }
};