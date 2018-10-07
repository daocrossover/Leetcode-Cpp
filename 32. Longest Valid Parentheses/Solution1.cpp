// Description:
// Given a string containing just the characters '(' and ')',
// find the length of the longest valid (well-formed) parentheses substring.

// Example 1:
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"

// Example 2:
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"


// Dynamic Programming Solution:
// dp[i]: the length of the longest valid substring ending at index i.
// It's obvious that the valid substrings must end with ')'.

// 1. If S[i] = ')' && S[i-1] = '(' -> S = "......()"
// dp[i] = dp[i-2] + 2

// 2. If S[i] = ')' && S[i-1] = ')' && S[i - dp[i-1] - 1] == '(' -> S = "......(,sub_s,)"
// If the character before sub_s happens to be '(', we update the dp[i] as an addition of 2 in the length of sub_s which is dp[i−1].
// To this, we also add the length of the valid substring just before the term "(,sub_s,)" , i.e. dp[i−dp[i−1]−2].
// dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0, n = s.length();
        vector<int> dp(n);
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                } else if (s[i-1] == ')') {
                    if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(') {
                        dp[i] = dp[i-1] + (i - dp[i-1] >= 2 ? dp[i - dp[i-1] - 2] : 0) + 2;
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};