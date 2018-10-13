// Description:
// In the "100 game," two players take turns adding, to a running total, any integer from 1..10.
// The player who first causes the running total to reach or exceed 100 wins.

// What if we change the game so that players cannot re-use integers?

// For example, two players might take turns drawing from a common pool of numbers of 1..15
// without replacement until they reach a total >= 100.

// Given an integer maxChoosableInteger and another integer desiredTotal,
// determine if the first player to move can force a win, assuming both players play optimally.

// You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

// Example
// Input:
// maxChoosableInteger = 10
// desiredTotal = 11
// Output:
// false

// Explanation:
// No matter which integer the first player choose, the first player will lose.
// The first player can choose an integer from 1 up to 10.
// If the first player choose 1, the second player can only choose integers from 2 up to 10.
// The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
// Same with other integers chosen by the first player, the second player will always win.


// DFS + Dynamic Programming:

#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<bool> used;
    unordered_map<int, bool> dp;
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1 + maxChoosableInteger) * maxChoosableInteger / 2; // both two players can't win
        if (sum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        used.resize(maxChoosableInteger + 1);
        return helper(desiredTotal);
    }
    
    bool helper(int desiredTotal) {
        if (desiredTotal <= 0) return false;
        int key = transfer(used);
        if (!dp.count(key)) {
            for (int i = 1; i < used.size(); ++i) {
                // try every unchosen number as next step
                if (!used[i]) {
                    used[i] = true;
                    // check whether this lead to a win (i.e. the other player lose)
                    if (!helper(desiredTotal - i)) {
                        dp[key] = true;
                        used[i] = false;
                        return true;
                    }
                    used[i] = false;
                }
            }
        }
        return dp[key];
    }
    
    // transfer vector<bool> to an Integer 
    int transfer(vector<bool> used) {
        int res = 0;
        for (int i = 0; i < used.size(); ++i) {
            res <<= 1;
            if (used[i]) res |= 1;
        }
        return res;
    }
};