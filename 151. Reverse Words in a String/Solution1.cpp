// Description:
// Given an input string, reverse the string word by word.

// Example 1:
// Input: "the sky is blue"
// Output: "blue is sky the"

// Example 2:
// Input: "  hello world!  "
// Output: "world! hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// Example 3:
// Input: "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 
// Note:
// 1. A word is defined as a sequence of non-space characters.
// 2. Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
// 3. You need to reduce multiple spaces between two words to a single space in the reversed string.
 
// Follow up:
// For C programmers, try to solve it in-place in O(1) extra space.

// In-place Solution:

#include <string>
using std::string;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end()); // reverse the whole string
        int start_index = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') continue;
            if (start_index != 0) s[start_index++] = ' '; // put a blank space in front of the word
            int j = i;
            // copy the word to the position staring from start_index
            while (j < s.length() && s[j] != ' ') s[start_index++] = s[j++];
            reverse(s.begin() + start_index - (j - i), s.begin() + start_index); // reverse each word
            i = j; // update the possible start of next word
        }
        s.erase(s.begin() + start_index, s.end());
        return s;
    }
};