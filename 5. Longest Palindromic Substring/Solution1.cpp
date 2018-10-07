// Description:
// Given a string s, find the longest palindromic substring in s.
// You may assume that the maximum length of s is 1000.

// Example 1:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// Example 2:
// Input: "cbbd"
// Output: "bb"


// Dynamic Programming Solution:
// dp[i][j] = 1 (S[i, j] is palindrome)
//          = 0 (otherwise)
// dp[i][j] = (dp[i+1][j-1] && S[i] == S[j])
// base cases: dp[i][i] = 1
//             dp[i][i+1] = (S[i] == S[i+1])
// Time complexity: O(n^2), Space complexity: O(n^2)

#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") return s;
        int n = s.length();
        int dp[n][n];
        int start = 0, end = 0, maxLen = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[j][i] = (s[j] == s[i] && (i - j <= 1 || dp[j+1][i-1]));
                // update maxLen and start and end of longestPalindrome
                if (dp[j][i] && maxLen < i - j + 1) {
                    maxLen = i - j + 1;
                    start = j;
                    end = i;
                }
            }
            dp[i][i] = 1;
        }
        return s.substr(start, end - start + 1);
    }
};