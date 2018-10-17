// Description:
// Given a string, find the length of the longest substring without repeating characters.

// Example 1:
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 

// Example 2:
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Hashmap + two pointers
// hashmap: key: character, value: index
// keep two pointers which define the max substring
// move the right pointer to scan through the string, and meanwhile update the hashmap.
// If the character is already in the hashmap, then move the left pointer to the right of the same character last found.
// Note that the two pointers can only move forward.

// Time Complexity: O(n). Index j will iterate n times.
// Space Complexity(HashMap): O(min(m, n)). We need O(k) space for the sliding window, where k is the size of the Set.
// The size of the Set is upper bounded by the size of the string n and the size of the charset/alphabet m.
// Space Complexity(Table): O(m). m is the size of the charset.

#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            if (hash.find(s[j]) != hash.end()) {
                // s = "abba", when j = 3, 'a' exists in hashmap, hash['a'] = 0
                // the new substring should start from the second b
                // Hence, the i should be max(i, hash[s[j]] + 1)
                i = max(i, hash[s[j]] + 1);
            }
            hash[s[j]] = j;
            res = max(res, j - i + 1);
        }
        return res;
    }

    // Using direct access table
    // int[26]: for Letters 'a' - 'z' or 'A' - 'Z'
    // int[128]: for ASCII
    // int[256]: for Extended ASCII
    int lengthOfLongestSubstring1(string s) {
        int index[128] = {0};
        int res = 0;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            i = max(index[s[j]], i);
            res = max(res, j - i + 1);
            index[s[j]] = j + 1;
        }
        return res;
    }
};