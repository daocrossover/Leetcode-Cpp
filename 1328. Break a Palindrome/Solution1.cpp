// 1328. Break a Palindrome
// Description:
// Given a palindromic string palindrome, replace exactly one character by any lowercase English letter 
// so that the string becomes the lexicographically smallest possible string that isn't a palindrome.
// After doing so, return the final string.  If there is no way to do so, return the empty string.

// Example 1:
// Input: palindrome = "abccba"
// Output: "aaccba"

// Example 2:
// Input: palindrome = "a"
// Output: ""
 
// Constraints:
// 1 <= palindrome.length <= 1000
// palindrome consists of only lowercase English letters.

#include <string>
using std::string;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        for (int i = 0; i < n / 2; ++i) {
            // change the first non 'a' character to 'a'.
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b'; // change the last character to 'b'
        return n > 1 ? palindrome : ""; // if palindrome is "a", return ""
    }
};