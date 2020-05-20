// Description:
// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
// Note that after backspacing an empty text, the text will continue empty.

// Example 1:
// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".

// Example 2:
// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".

// Example 3:
// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".

// Example 4:
// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".

// Note:
// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.

// Follow up:
// Can you solve it in O(N) time and O(1) space?

// Build string using stack
// Time Complexity: O(M + N), where M and N are the lengths of S and T respectively.
// Space Complexity: O(M + N)

#include<string>
#include<stack>
using std::string;
using std::stack;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return construct(S) == construct(T);
    }
    
    string construct(string s) {
        stack<int> st;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '#') {
                st.push(s[i]);
            } else if (!st.empty()) {
                st.pop();
            }
        }
        string str;
        while (!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        return str;
    }
};