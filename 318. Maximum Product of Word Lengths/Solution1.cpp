// Description:
// Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
// You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

// Example 1:
// Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16 
// Explanation: The two words can be "abcw", "xtfn".

// Example 2:
// Input: ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4 
// Explanation: The two words can be "ab", "cd".

// Example 3:
// Input: ["a","aa","aaa","aaaa"]
// Output: 0 
// Explanation: No such pair of words.

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isShare(string& str1, string& str2) {
        vector<bool> flag(26);
        for (auto c : str1) {
            flag[c - 'a'] = true;
        }
        for (auto c : str2) {
            if (flag[c - 'a'])
                return true;
        }
        return false;
    }
    
    int maxProduct(vector<string>& words) {
        if (words.size() < 2) return 0;
        int res = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i+1; j < words.size(); ++j) {
                if (!isShare(words[i], words[j]))
                    res = max(res, (int)words[i].length() * (int)words[j].length());
            }
        }
        return res;
    }
};