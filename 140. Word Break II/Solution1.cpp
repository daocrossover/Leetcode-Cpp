// Description:
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
// add spaces in s to construct a sentence where each word is a valid dictionary word.
// Return all such possible sentences.

// Note:
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.

// Example 1:
// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]

// Example 2:
// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.

// Example 3:
// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []

// backtracking && DP

#include<unordered_map>
#include<vector>
#include<string>
using namespace std;

class Solution {
    // Dynamic Programming: add memorization to the recursive solution
    unordered_map<string, vector<string>> hash;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // find s in hashmap
        if (hash.count(s)) return hash[s];
        vector<string> res;
        for (int i = 1; i <= s.length(); ++i) {
            string word = s.substr(0, i);
            string rest = s.substr(i);
            if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                if (rest.size() == 0) {
                    res.push_back(word);
                } else {
                    // solve rest recursively
                    vector<string> strs = wordBreak(rest, wordDict);
                    // combine the word and the str in strs
                    for (string str : strs) {
                        res.push_back(word + " " + str);
                    }
                }
            }
        }
        hash[s] = res;
        return res;
    }
};