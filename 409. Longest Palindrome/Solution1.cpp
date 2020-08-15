// Description:
// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
// This is case sensitive, for example "Aa" is not considered a palindrome here.

// Note:
// Assume the length of given string will not exceed 1,010.

// Example:
// Input:
// "abccccdd"
// Output:
// 7
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

// HashSet Solution:

#include <string>
#include <unordered_set>
using std::string;
using std::unordered_set;

class Solution {
public:
    int longestPalindrome(string s) {
        int len = 0;
        unordered_set<char> st;
        for (char c: s) {
            if (st.find(c) != st.end()) {
                st.erase(c);
                len += 2;
            } else {
                st.insert(c);
            }
        }
        return st.empty() ? len : len + 1;
    }
};