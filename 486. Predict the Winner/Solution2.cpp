// Minimax Solution + Dynamic Programming(memoization):
// Time Complexity: O(n^2), Space Complexity: O(n^2)

#include<vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // use of a 2-D memoization array dp such that we can store the result obtained
        // for the function call winner for a subarray with starting and ending indices being s and e at dp[s][e]
        vector<vector<int>> dp(n, vector<int>(n));
        return winner(nums, 0, n - 1, dp) >= 0;
    }
    
    int winner(vector<int>& nums, int s, int e, vector<vector<int>>& dp) {
        if (s == e) return nums[s];
        if (dp[s][e]) return dp[s][e];
        // if it's player1's turn, he will choose nums[s] or nums[e]
        // the score that the player2 could obtain in the next turn will be
        // winner(nums, s + 1, e, dp) or winner(nums, s, e - 1, dp)
        // effective score of player1 at the current instant is the substract between them.
        int begin = nums[s] - winner(nums, s + 1, e, dp);
        int end = nums[e] - winner(nums, s, e - 1, dp);
        // return the larger of the effective scores possible
        // by choosing either the first or the last element from the currently available subarray.
        dp[s][e] = max(begin, end);
        return dp[s][e];
    }
};