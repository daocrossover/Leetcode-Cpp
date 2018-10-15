// Dynamic Programming: top-down
// dp[i][j]: the longest palindromic subsequence's length of substring(i, j)
// dp[i][j] = dp[i+1][j-1] + 2, if s[i] == s[j]
//          = max(dp[i+1][j], dp[i][j-1]), otherwise
// Initialization: dp[i][i] = 1
// may Memory Limit Exceed in some cases

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n));
        return helper(s, 0, s.length() - 1, dp);
    }

    int helper(string s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j]) return dp[i][j];
        if (s[i] == s[j]) {
            dp[i][j] = helper(s, i + 1, j - 1, dp) + 2;
        } else {
            dp[i][j] = max(helper(s, i + 1, j, dp), helper(s, i, j - 1, dp));
        }
        return dp[i][j];
    }
};