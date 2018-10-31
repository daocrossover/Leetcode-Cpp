// Description:
// Given a string, your task is to count how many palindromic substrings in this string.

// The substrings with different start indexes or
// end indexes are counted as different substrings even they consist of same characters.

// Example 1:
// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

// Note:
// The input string length won't exceed 1000.


// Dynamic Programming Solution:
// dp[i][j]: whether s[i, j] a is palindromic string
// Time Complexity: O(n^2), Space Complexity: O(n^2)

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
                if (dp[i][j]) ++res;
            }
        }
        return res;
    }
};