// Description:
// Given a pattern and a string str, find if str follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Example 1:
// Input: pattern = "abba", str = "dog cat cat dog"
// Output: true

// Example 2:
// Input:pattern = "abba", str = "dog cat cat fish"
// Output: false

// Example 3:
// Input: pattern = "aaaa", str = "dog cat cat dog"
// Output: false

// Example 4:
// Input: pattern = "abba", str = "dog dog dog dog"
// Output: false

// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.

#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
using std::string;
using std::istringstream;
using std::unordered_map;
using std::vector;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        unordered_map<string, char> s2c;
        unordered_map<char, string> c2s;
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        if (words.size() != pattern.size()) {
            return false;
        }
        for (int i = 0; i < words.size(); ++i) {
            char c = pattern[i];
            string s = words[i];
            if (s2c.find(s) == s2c.end() && c2s.find(c) == c2s.end()) {
                s2c[s] = c;
                c2s[c] = s;
                continue;
            }
            if (s2c[s] != c || c2s[c] != s) return false;
        }
        return true;
    }
};