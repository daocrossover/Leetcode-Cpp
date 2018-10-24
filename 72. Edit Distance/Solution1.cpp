// Description:
// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

// You have the following 3 operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')


// Dynamic Programming Solution:
// Like the Sequence Alignment Problem
// dp[i][j]: the edit distance between word1[0, i-1] and word2[0, j-1]
// dp[m][n]: the edit distance between word1 and word2
// dp[i][j] = min dp[i-1][j] + 1 -> add
//                dp[i][j-1] + 1 -> delete
//                dp[i-1][j-1] + 1 (word1[i] != word2[j]) -> replace
//                dp[i-1][j-1] (word1[i] == word2[j])

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        // Initialization:
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (word1[i] == word2[j])
                    dp[i+1][j+1] = dp[i][j];
                else
                    dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]), dp[i][j]) + 1;
            }
        }
        return dp[m][n];
    }
};