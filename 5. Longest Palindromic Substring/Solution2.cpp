// Expand Around Center Solution:
// A palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center,
// and there are only 2n−1 such centers.
// The center of a palindrome can be a letter or in between two letters.
// Time complexity: O(n^2), Space complexity: O(1)

#include<string>
using namespace std;

class Solution {
    int maxLen = 0;
    int start = 0;
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        for (int i = 0; i < s.length() - 1; ++i) {
            expandPalindrome(s, i, i); // expand odd length
            expandPalindrome(s, i, i + 1); // expand even length
        }
        return s.substr(start, maxLen);
    }
    
    void expandPalindrome(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // length of new palindrome is right - left - 1
        if (maxLen < right - left - 1) {
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};