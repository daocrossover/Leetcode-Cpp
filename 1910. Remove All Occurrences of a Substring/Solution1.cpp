// 1910. Remove All Occurrences of a Substring
// Description:
// Given two strings s and part, perform the following operation on s 
// until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

// Example 1:
// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc".

// Example 2:
// Input: s = "axxxxyyyyb", part = "xy"
// Output: "ab"
// Explanation: The following operations are done:
// - s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
// - s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
// - s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
// - s = "axyb", remove "xy" starting at index 1 so s = "ab".
// Now s has no occurrences of "xy".

// Constraints:
// 1 <= s.length <= 1000
// 1 <= part.length <= 1000
// s and part consists of lowercase English letters.

// Stack Solution:
// If the last characters of the pattern size in the stack match the pattern remove them

#include <stack>
#include <string>
using std::stack;
using std::string;

class Solution {
public:
    bool match(stack<char> s, string part) {
        int n = part.length();
        int j = n - 1;
        while (j >= 0 && s.top() == part[j]) {
            s.pop();
            j--;
        }
        return j == -1;
    }
    
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int n1 = s.length(), n2 = part.length();
        for (int i = 0; i < n1; ++i) {
            st.push(s[i]);
            if (st.size() >= n2) {
                if (match(st, part)) {
                    for (int j = 0; j < n2; ++j) {
                        st.pop();
                    }
                }
            }
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};