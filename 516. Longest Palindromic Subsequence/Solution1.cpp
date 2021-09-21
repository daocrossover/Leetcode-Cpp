// 516. Longest Palindromic Subsequence
// Description:
// Given a string s, find the longest palindromic subsequence's length in s.
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Example 1:
// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".

// Example 2:
// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

// Constraints:
// 1. 1 <= s.length <= 1000
// 2. s consists only of lowercase English letters.

// Dynamic Programming: bottom-up
// dp[i][j]: the longest palindromic subsequence's length of substring(i, j)
// dp[i][j] = dp[i+1][j-1] + 2, if s[i] == s[j]
//          = max(dp[i+1][j], dp[i][j-1]), otherwise
// Initialization: dp[i][i] = 1
// Since using i + 1 each time, for the i loop, we need to start from the n - 1
// And j starts from i + 1 because we want to calculate the inner substring first

#include <vector>
#include <string>
using std::vector;
using std::string;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};