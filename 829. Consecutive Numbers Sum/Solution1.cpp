// 829. Consecutive Numbers Sum
// Description:
// Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.

// Example 1:
// Input: n = 5
// Output: 2
// Explanation: 5 = 2 + 3

// Example 2:
// Input: n = 9
// Output: 3
// Explanation: 9 = 4 + 5 = 2 + 3 + 4

// Example 3:
// Input: n = 15
// Output: 4
// Explanation: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
 
// Constraints:
// 1 <= n <= 109

// Solution:
// N = x + (x + 1) + (x + 2) + ... + (x + i - 1) where x is a positive integer and 
// there are i terms in the RHS
// (x + (x + i - 1)) * i / 2 = N
// x * i = N - i * (i - 1) / 2
// we need to find the number of x such that N - i * (i - 1) / 2) % i == 0
// since x * i > 0, i * (i - 1) / 2 < N in the for loop

// Time Complexity: O(sqrt(N))

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for (int i = 1; i * (i - 1) / 2 < n; ++i) {
            if ((n - i * (i - 1) / 2) % i == 0) {
                count++;
            }
        }
        return count;
    }
};