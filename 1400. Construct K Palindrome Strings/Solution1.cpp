// 1400. Construct K Palindrome Strings
// Description:
// Given a string s and an integer k. You should construct k non-empty palindrome strings using all the characters in s.
// Return True if you can use all the characters in s to construct k palindrome strings or False otherwise.

// Example 1:
// Input: s = "annabelle", k = 2
// Output: true
// Explanation: You can construct two palindromes using all characters in s.
// Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

// Example 2:
// Input: s = "leetcode", k = 3
// Output: false
// Explanation: It is impossible to construct 3 palindromes using all the characters of s.

// Example 3:
// Input: s = "true", k = 4
// Output: true
// Explanation: The only possible solution is to put each character in a separate string.

// Example 4:
// Input: s = "yzyzyzyzyzyzyzy", k = 2
// Output: true
// Explanation: Simply you can put all z's in one string and all y's in the other string. Both strings will be palindrome.

// Example 5:
// Input: s = "cr", k = 7
// Output: false
// Explanation: We don't have enough characters in s to construct 7 palindromes.

// Constraints:
// 1 <= s.length <= 10^5
// All characters in s are lower-case English letters.
// 1 <= k <= 10^5

// HashMap Solution:
// Each palindrome at most has one character with odd times of occurrence
// Non-empty means each palindrome at least has one character, hence k <= s.length()

#include <string>
using std::string;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();
        if (k > n) {
            return false;
        }
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }
        int odd_num = 0;
        for (int i = 0; i < 26; ++i) {
            odd_num += count[i] % 2;
        }
        return odd_num <= k;
    }
};