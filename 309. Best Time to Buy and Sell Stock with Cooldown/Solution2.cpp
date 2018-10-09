// Dynamic Programming Solution:
// buy[i] means before day i what is the maxProfit for any sequence end with buy.
// sell[i] means before day i what is the maxProfit for any sequence end with sell.
// rest[i] means before day i what is the maxProfit for any sequence end with rest.

// Then we want to deduce the transition functions for buy sell and rest.
// By definition we have:
// buy[i]  = max(rest[i-1]-price, buy[i-1]) 
// sell[i] = max(buy[i-1]+price, sell[i-1])
// rest[i] = max(sell[i-1], buy[i-1], rest[i-1])

// Where price is the price of day i. All of these are very straightforward.
// They simply represents :
// (1) We have to rest before we buy and 
// (2) we have to buy before we sell

// Hence, we can conclude that
// (1) buy[i] <= rest[i] -> rest[i] = max(sell[i-1], rest[i-1]) and [buy, rest, buy] is never occurred.
// (2) rest[i] <= sell[i] -> rest[i] = sell[i-1]

// Then the transition functions could be turned to:
// buy[i] = max(sell[i-2]-price, buy[i-1])
// sell[i] = max(buy[i-1]+price, sell[i-1])

// Even the space complexity could be reduced from O(n) to O(1)!

#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sell = 0, prev_sell = 0, prev_buy;
        for (int price : prices) {
            prev_buy = buy;
            buy = max(prev_sell - price, prev_buy);
            prev_sell = sell;
            sell = max(prev_buy + price, prev_sell);
        }
        return sell;
    }
};