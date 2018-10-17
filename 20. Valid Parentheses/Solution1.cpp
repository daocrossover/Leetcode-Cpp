// Description:
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.

// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// Note that an empty string is also considered valid.

// Example 1:
// Input: "()"
// Output: true

// Example 2:
// Input: "()[]{}"
// Output: true

// Example 3:
// Input: "(]"
// Output: false

// Example 4:
// Input: "([)]"
// Output: false

// Example 5:
// Input: "{[]}"
// Output: true


// Using stack

#include<stack>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> hash{{'(', ')'}, {'[', ']'}, {'{', '}'}};
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            // when meet open brackets, push to the stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // if the top of stack match with the current c, pop
                if (!st.empty() && hash[st.top()] == c) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        // if valid, the stack finally should be empty
        return st.empty();
    }
};