// 453. Minimum Moves to Equal Array Elements
// Description:
// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment n - 1 elements of the array by 1.

// Example 1:
// Input: nums = [1,2,3]
// Output: 3
// Explanation: Only three moves are needed (remember each move increments two elements):
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

// Example 2:
// Input: nums = [1,1,1]
// Output: 0

// Constraints:
// n == nums.length
// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9
// The answer is guaranteed to fit in a 32-bit integer.

// Math Solution:
// sum: sum of all the numbers, before any moves
// minNum: min number the list
// n: the length of the list
// After, say m moves, we get all the numbers as x, and we will get the following equation
// sum + m * (n - 1) = x * n
// And the minNum will always be minmum until it reachs the final number, because every move, other numbers (besides the max) will be increamented too
// From above, we can get, the minNum will be incremented in every move. 
// So, if the final number is x, x = minNum + m
// Therefore, m = sum - minNum * n

#include <vector>
using std::vector;
using std::min;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, min_num = INT_MAX;
        for (int num : nums) {
            sum += num;
            min_num = min(min_num, num);
        }
        return sum - min_num * n;
    }
};