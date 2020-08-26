// Description:
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Note:
// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like ? or *.

// Example 1:
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".

// Example 2:
// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.

// Example 3:
// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

// Example 4:
// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

// Example 5:
// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false

// Gready Solution
// if you have multiple * in pattern, you check match for last

#include <string>
using std::string;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, match = 0, asterisk = -1;
        int m = s.length(), n = p.length();
        while (i < m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')) {
                // advancing both pointers when both characters match or '?' found in pattern
                i++;
                j++;
            } else if (j < n && p[j] == '*') {
                // * found in pattern, track index of *, only advancing pattern pointer
                match = i;
                asterisk = j++;
            } else if (asterisk >= 0) {
                // current characters don't match, last pattern pointer was *, current pattern pointer is not *
                i = ++match;
                j = asterisk + 1;
            } else {
                return false;
            }
        }
        while (j < n && p[j] == '*') j++; // check for remaining characters in pattern
        return j == n;
    }
};