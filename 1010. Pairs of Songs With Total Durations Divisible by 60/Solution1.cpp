// 1010. Pairs of Songs With Total Durations Divisible by 60
// Description:
// You are given a list of songs where the ith song has a duration of time[i] seconds.
// Return the number of pairs of songs for which their total duration in seconds is divisible by 60. 
// Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

// Example 1:
// Input: time = [30,20,150,100,40]
// Output: 3
// Explanation: Three pairs have a total duration divisible by 60:
// (time[0] = 30, time[2] = 150): total duration 180
// (time[1] = 20, time[3] = 100): total duration 120
// (time[1] = 20, time[4] = 40): total duration 60

// Example 2:
// Input: time = [60,60,60]
// Output: 3
// Explanation: All three pairs have a total duration of 120, which is divisible by 60.

// Constraints:
// 1. 1 <= time.length <= 6 * 10^4
// 2. 1 <= time[i] <= 500

// Solution:
// Two-sum question with target = 60, each item in time % 60
// Let t1 be in the pair with t, (t + t1) % 60 = 0
// t % 60 + t1 % 60 = 0 or 60
// When t1 % 60 = 60 - t % 60, want to combine these two scenarios
// If t % 60 == 0, 60 - t % 60 == 60, but t1 % 60 can not be 60
// Therefore, t1 % 60 = (60 - t % 60) % 60
// Since 0 <= t1 < 60 (% 60 before), t1 % 60 = t1
// So, we have t1 = (60 - t % 60) % 60

#include <vector>
using std::vector;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        vector<int> count(60);
        for (int t : time) {
            res += count[(60 - t % 60) % 60];
            count[t % 60]++;
        }
        return res;
    }
};