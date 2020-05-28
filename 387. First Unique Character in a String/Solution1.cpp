// Description:
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:
// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.

// Note: You may assume the string contain only lowercase letters.

// Solution 1: HashMap

#include<string>
#include<unordered_map>
using std::string;
using std::unordered_map;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> dict;
        for (int i = 0; i < s.length(); ++i) {
            dict[s[i]]++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (dict[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};