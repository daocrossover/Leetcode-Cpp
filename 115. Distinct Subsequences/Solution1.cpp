// Description:
// Given a string S and a string T, count the number of distinct subsequences of S which equals T.

// A subsequence of a string is a new string which is formed from the original string
// by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
// (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// Example 1:
// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)

// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^

// Example 2:
// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)

// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag


// Dynamic Programming Solution:
// dp[i][j]: the number of distinct subsequences of t[0...i-1] in s[0...j-1].
// 1. dp[i][j] = dp[i][j-1] if t[i-1] != s[j-1];
// 2. dp[i][j] = dp[i][j-1] + dp[i-1][j-1] if t[i-1] == s[j-1];
// the number of distinct subsequences include two parts: those with t[i-1] and those without;
// 3. dp[0][j] = 1 for all j;
// An empty string will have exactly one subsequence in any string
// 4. dp[i][0] = 0 for all positive i.
// Non-empty string will have no subsequences in an empty string.

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int j = 0; j <= n; ++j) dp[0][j] = 1;
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= m; ++i) {
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1] : 0);
            }
        }        
        return dp[m][n];
    }
};