// Description:
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// Example 1:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true

// Example 2:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false


// Dynamic Programming Solution:
// the letter order of s1 in s3 should be the same as the order in s1.
// can not use merging, because when s[i] == s[j],
// we don't know where the letter comes from.
// dp[i][j]: s1[0, i-1] and s2[0, j-1] match with s3[0, i+j-1]
// Time Complexity: O(m*n), Space Complexity: O(m*n)

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) return false;
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if (i == 0) {
                    dp[i][j] = (s2[j-1] == s3[i+j-1]) & dp[i][j-1];
                } else if (j == 0) {
                    dp[i][j] = (s1[i-1] == s3[i+j-1]) & dp[i-1][j];
                } else {
                    dp[i][j] = ((s1[i-1] == s3[i+j-1]) & dp[i-1][j]) || ((s2[j-1] == s3[i+j-1]) & dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};