// Description:
// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of s.

// Example:
// Input: "aab"
// Output: 1
// Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.


// Dynamic Programming Solution:
// dp[i]: the minimum cuts needed for section s[0, i]
// dp[i] = min(dp[j-1] + 1) (0 <= j <= i) if s[j, i] is palindrome
// If s[j, i] is palindrome, s[j+1, i-1] is palindrome, and c[j] == c[i].

#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n);
        // need to cache the information whether s[j, i] is palindrome
        vector<vector<bool>> P(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            // initialize min cuts = i, considering every letter in string may be different
            int cut = i;
            for (int j = 0; j <= i; ++j) {
                // s[j] == s[i] && the length of s[j, i] <= 2 -> P[j][i] = true
                if (s[j] == s[i] && (i-j <= 1 || P[j+1][i-1])) {
                    P[j][i] = true;
                    cut = (j == 0) ? 0 : min(cut, dp[j-1] + 1);
                }
            }
            dp[i] = cut;
        }
        return dp[n-1];
    }
};