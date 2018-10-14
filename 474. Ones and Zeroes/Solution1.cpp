// Description:
// In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.

// For now, suppose you are a dominator of m 0s and n 1s respectively.
// On the other hand, there is an array with strings consisting of only 0s and 1s.

// Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s.
// Each 0 and 1 can be used at most once.

// Note:
// The given numbers of 0s and 1s will both not exceed 100
// The size of given string array won't exceed 600.

// Example 1:
// Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
// Output: 4
// Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”

// Example 2:
// Input: Array = {"10", "0", "1"}, m = 1, n = 1
// Output: 2
// Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".


// 0/1 Knapsack Problem with two resources
// 3D Dynamic Programming Solution:
// dp(i,m,n) = maximum number of strings that you can form with strings 1…i & remaining m 0s & n 1s
// dp(i,m,n) = dp(i-1,m,n) if string i requires more 0s or 1s available
//           = max(1 + dp(i-1,m-Si1,n-Si0), dp(i-1,m,n)) otherwise
// Si1: the number of 1s in string i and Si0: the number of 0s in string i

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>> dp(l+1, vector<vector<int>>(m+1, vector<int>(n+1)));
        for (int i = 1; i <= l; ++i) {
            string s = strs[i-1];
            int ones = count(s.begin(), s.end(), '1');
            int zeros = s.size() - ones;
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    if (j >= zeros && k >= ones)
                        dp[i][j][k] = max(dp[i-1][j][k], 1 + dp[i-1][j-zeros][k-ones]);
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        return dp[l][m][n];
    }
};