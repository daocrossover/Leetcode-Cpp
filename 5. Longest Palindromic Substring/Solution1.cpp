// 5. Longest Palindromic Substring
// Description:
// Given a string s, find the longest palindromic substring in s.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

// Example 3:
// Input: s = "a"
// Output: "a"

// Example 4:
// Input: s = "ac"
// Output: "a"

// Constraints:
// 1 <= s.length <= 1000
// s consist of only digits and English letters.

// Dynamic Programming Solution:
// dp[i][j] = 1 (S[i, j] is palindrome)
//          = 0 (otherwise)
// dp[i][j] = (dp[i+1][j-1] && S[i] == S[j])
// base cases: dp[i][i] = 1
//             dp[i][i+1] = (S[i] == S[i+1])
// Time complexity: O(n^2)
// Space complexity: O(n^2)

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") return s;
        int n = s.length();
        int start = 0, max_len = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = s[i] == s[j] && (j - i <= 2 || dp[i+1][j-1]);
                if (dp[i][j] && max_len < j - i + 1) {
                    max_len = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, max_len);
    }

    string longestPalindrome1(string s) {
        if (s == "") return s;
        int n = s.length();
        int dp[n][n];
        int start = 0, maxLen = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[j] == s[i] && (i - j <= 1 || dp[j+1][i-1]));
                // update maxLen and start and end of longestPalindrome
                if (dp[j][i] && maxLen < i - j + 1) {
                    maxLen = i - j + 1;
                    start = j;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(start, maxLen);
    }
};