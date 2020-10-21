// 1048. Longest String Chain
// Description:
// Given a list of words, each word consists of English lowercase letters.
// Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2. 
// For example, "abc" is a predecessor of "abac".

// A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, 
// where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

// Return the longest possible length of a word chain with words chosen from the given list of words.

// Example 1:
// Input: ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: one of the longest word chain is "a","ba","bda","bdca".

// Note:
// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of English lowercase letters.

#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;
using std::max;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& s1, string& s2) {
            return s1.size() < s2.size();
        });
        int res = 0;
        unordered_map<string, int> dp;
        for (string w: words) {
            for (int i = 0; i < w.size(); ++i) {
                // loop on all possible previous word with 1 letter missing
                string prev = w.substr(0, i) + w.substr(i + 1);
                // if we have seen this previous word, update the longest chain for the current word
                dp[w] = max(dp[w], dp[prev] + 1);
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};