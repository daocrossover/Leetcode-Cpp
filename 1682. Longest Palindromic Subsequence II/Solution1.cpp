// 1682. Longest Palindromic Subsequence II
// Description:
// A subsequence of a string s is considered a good palindromic subsequence if:
// It is a subsequence of s.
// It is a palindrome (has the same value if reversed).
// It has an even length.
// No two consecutive characters are equal, except the two middle ones.

// For example, if s = "abcabcabb", then "abba" is considered a good palindromic subsequence, 
// while "bcb" (not even length) and "bbbb" (has equal consecutive characters) are not.

// Given a string s, return the length of the longest good palindromic subsequence in s.

// Example 1:
// Input: s = "bbabab"
// Output: 4
// Explanation: The longest good palindromic subsequence of s is "baab".

// Example 2:
// Input: s = "dcbccacdb"
// Output: 4
// Explanation: The longest good palindromic subsequence of s is "dccd".

// Constraints:
// 1. 1 <= s.length <= 250
// 2. s consists of lowercase English letters.

// Following-up of the 516. Longest Palindromic Subsequence
// Dynamic Programming:
// dp[i][j][k]: length of the longest palindromic subsequence from i to j where the outmost letter is the k-th letter (0-indexed).
// For each pair of (i, j) where i < j, loop over k. Let c be the k-th letter. 
// If s[i] != c, then dp[i][j][k] = dp[i + 1][j][k]. 
// If s[j] != c, then dp[i][j][k] = dp[i][j - 1][k]. 
// Otherwise, loop over m from 0 to 25 and calculate the maximum previous length as 
// prevLength = max{dp[i + 1][j - 1][m]} among the values of m where m != k. 
// Then dp[i][j][k] = prevLength + 2.
// After the values of dp are calculated, loop over k from 0 to 25 to obtain the maximum among dp[0][n - 1][k].

#include <vector>
#include <string>
using std::vector;
using std::string;
using std::max;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(26)));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                for (int k = 0; k < 26; k++) {
                    char c = 'a' + k;
                    if (s[i] != c) {
                        dp[i][j][k] = dp[i + 1][j][k];
                    } else if (s[j] != c) {
                        dp[i][j][k] = dp[i][j - 1][k];
                    } else {
                        int prev_len = 0;
                        for (int m = 0; m < 26; m++) {
                            if (m != k) {
                                // here is to satisfy 'No two consecutive characters are equal, except the two middle ones.'
                                prev_len = max(prev_len, dp[i + 1][j - 1][m]);
                            }
                        }
                        dp[i][j][k] = prev_len + 2;
                    }
                }
            }
        }
        int max_len = 0;
        for (int k = 0; k < 26; k++) {
            max_len = max(max_len, dp[0][n - 1][k]);
        }
        return max_len;
    }
};