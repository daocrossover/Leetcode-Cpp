// Description:
// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces .
// The integer division should truncate toward zero.

// Example 1:
// Input: "3+2*2"
// Output: 7

// Example 2:
// Input: " 3/2 "
// Output: 1

// Example 3:
// Input: " 3+5 / 2 "
// Output: 5

// Note:
// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.

// One-stack Solution:
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stack>
#include <string>
using std::string;
using std::stack;

class Solution {
public:
    int calculate(string s) {
        long res = 0, num = 0, n = s.size();
        char op = '+';
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0'; // pay attention to overflow
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
                if (op == '+') st.push(num);
                if (op == '-') st.push(-num);
                if (op == '*' || op == '/') {
                    int tmp = (op == '*') ? st.top() * num : st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = s[i];
                num = 0;
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};