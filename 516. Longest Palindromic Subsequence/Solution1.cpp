// Description:
// Given a string s, find the longest palindromic subsequence's length in s.
// You may assume that the maximum length of s is 1000.

// Example 1:
// Input:
// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".

// Example 2:
// Input:
// "cbbd"
// Output:
// 2
// One possible longest palindromic subsequence is "bb".


// Dynamic Programming: bottom-up
// dp[i][j]: the longest palindromic subsequence's length of substring(i, j)
// dp[i][j] = dp[i+1][j-1] + 2, if s[i] == s[j]
//          = max(dp[i+1][j], dp[i][j-1]), otherwise
// Initialization: dp[i][i] = 1

#include<vector>
#include<string>
using namespace std;

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
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};