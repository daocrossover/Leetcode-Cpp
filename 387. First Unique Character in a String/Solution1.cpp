// 387. First Unique Character in a String
// Description:
// Given a string s, find the first non-repeating character in it and 
// return its index. If it does not exist, return -1.

// Example 1:
// Input: s = "leetcode"
// Output: 0

// Example 2:
// Input: s = "loveleetcode"
// Output: 2

// Example 3:
// Input: s = "aabb"
// Output: -1
 
// Constraints:
// 1 <= s.length <= 10^5
// s consists of only lowercase English letters.

// Solution 1: HashMap

#include <string>
#include <unordered_map>
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