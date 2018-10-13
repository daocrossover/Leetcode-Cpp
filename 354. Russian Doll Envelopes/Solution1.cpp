// Description:
// You have a number of envelopes with widths and heights given as a pair of integers (w, h).
// One envelope can fit into another if and only if both the width and height of one envelope is greater than
// the width and height of the other envelope.

// What is the maximum number of envelopes can you Russian doll? (put one inside other)

// Note:
// Rotation is not allowed.

// Example:
// Input: [[5,4],[6,4],[6,7],[2,3]]
// Output: 3 
// Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).


// Dynamic Programming Solution:
// first sorting, then it is the same as Longest Increasing Subsequence problem
// Time Complexity: O(n^2), Space Complexity: O(n)

#include<vector>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;
        sort(envelopes.begin(), envelopes.end());
        // Longest Increasing Subsequence
        int maxLen = 1;
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int m = 0;
            for (int j = 0; j < i; ++j) {
                if (envelopes[j].first < envelopes[i].first && 
                   envelopes[j].second < envelopes[i].second) {
                    m = max(m, dp[j]);
                }
            }
            dp[i] = m + 1;
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};