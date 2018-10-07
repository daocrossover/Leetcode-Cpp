// Stack Solution:
// For every '(' encountered, we push its index onto the stack.
// For every ')' encountered, we pop the topmost element and subtract the current element's index from the top element of the stack,
// which gives the length of the currently encountered valid string of parentheses.
// If while popping the element, the stack becomes empty, we push the current element's index onto the stack.

#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        // key: push -1 onto the stack first
        st.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};