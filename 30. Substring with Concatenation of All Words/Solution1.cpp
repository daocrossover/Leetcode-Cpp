// Description:
// You are given a string, s, and a list of words, words, that are all of the same length.
// Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

// Example 1:
// Input:
//   s = "barfoothefoobarman",
//   words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
// The output order does not matter, returning [9,0] is fine too.

// Example 2:
// Input:
//   s = "wordgoodstudentgoodword",
//   words = ["word","student"]
// Output: []


// Two HashMap Solution:

#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.size() == 0 || s.length() == 0) return res;
        unordered_map<string, int> hash;
        // hash record the expected times of each word and another
        for (int i = 0; i < words.size(); ++i) {
            hash[words[i]]++;
        }
        int m = s.length(), n = words.size(), len = words[0].length();
        for (int i = 0; i <= m - len * n; ++i) {
            // record the times we have seen
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < n; ++j) {
                string word = s.substr(i + j * len, len);
                if (hash.find(word) != hash.end()) {
                    seen[word]++;
                    if (seen[word] > hash[word])
                        break;
                } else {
                    break;
                }
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};