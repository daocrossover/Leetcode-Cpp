// Description:
// Given an array of scores that are non-negative integers.
// Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on.
// Each time a player picks a number, that number will not be available for the next player.
// This continues until all the scores have been chosen. The player with the maximum score wins.

// Given an array of scores, predict whether player 1 is the winner.
// You can assume each player plays to maximize his score.

// Example 1:
// Input: [1, 5, 2]
// Output: False
// Explanation: Initially, player 1 can choose between 1 and 2. 
// If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5.
// If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
// So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
// Hence, player 1 will never be the winner and you need to return False.

// Example 2:
// Input: [1, 5, 233, 7]
// Output: True
// Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7.
// No matter which number player 2 choose, player 1 can choose 233.
// Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

// Note:
// 1 <= length of the array <= 20.
// Any scores in the given array are non-negative integers and will not exceed 10,000,000.
// If the scores of both players are equal, then player 1 is still the winner.


// Minimax Solution:
// Time Complexity: O(2^n), Space Complexity: O(n)

#include<vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums, 0, 0, 1);
    }
    
    bool canWin(vector<int> nums, int sum1, int sum2, int player) {
        if (nums.empty()) return sum1 >= sum2;
        if (nums.size() == 1) {
            if (player == 1) return sum1 + nums[0] >= sum2;
            else return sum2 + nums[0] > sum1;
        }
        vector<int> begin = vector<int>(nums.begin() + 1, nums.end());
        vector<int> end = vector<int>(nums.begin(), nums.end() - 1);
        if (player == 1)
            // case 1: player1 choose the first element in the array
            // case 2: player1 choose the last element in the array
            // if either case 1 or case 2 could lead to loss of player 2
            // return true
            return !canWin(begin, sum1 + nums[0], sum2, 2) || !canWin(end, sum1 + nums.back(), sum2, 2);
        else
            // vice versa
            return !canWin(begin, sum1, sum2 + nums[0], 1) || !canWin(end, sum1, sum2 + nums.back(), 1);
    }
};

// other version: Solution2 without memorization
// class Solution {
// public:
//     bool PredictTheWinner(vector<int>& nums) {
//         return winner(nums, 0, nums.size() - 1) >= 0;
//     }
    
//     int winner(vector<int>& nums, int s, int e) {
//         if (s == e) return nums[s];
//         // if it's player1's turn, he will choose nums[s] or nums[e]
//         // the score that the player2 could obtain in the next turn will be
//         // winner(nums, s + 1, e, dp) or winner(nums, s, e - 1, dp)
//         // effective score of player1 at the current instant is the substract between them.
//         int begin = nums[s] - winner(nums, s + 1, e, dp);
//         int end = nums[e] - winner(nums, s, e - 1, dp);
//         // return the larger of the effective scores possible
//         // by choosing either the first or the last element from the currently available subarray.
//         return max(begin, end);
//     }
// };