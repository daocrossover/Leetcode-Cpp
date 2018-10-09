// Description:
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
// determine if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note:
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.

// Example 1:
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

// Example 2:
// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.

// Example 3:
// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false


// Dynamic Programming Solution:
// dp[i]: if dp[i] is 1, then s[0, i-1] is a valid word made of words in dictionary.

#include<vector>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (dp[j]) {
                    string word = s.substr(j, i-j);
                    if (wordSet.find(word) != wordSet.end()) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};