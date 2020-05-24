// Description:
// Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid.
// We define the validity of a string by these rules:
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
// An empty string is also valid.

// Example 1:
// Input: "()"
// Output: True

// Example 2:
// Input: "(*)"
// Output: True

// Example 3:
// Input: "(*))"
// Output: True

// Note:
// The string size will be in the range [1, 100].

// Greedy solution:
// min_left_op: smallest possible number of open left brackets
// max_left_op: largest possible number of open left brackets
// Time Complexity: O(N)
// Space Complexity: O(1)

#include<string>
#include<algorithm>
using std::string;
using std::max;

class Solution {
public:
    bool checkValidString(string s) {
        int min_left_op = 0, max_left_op = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                min_left_op++;
                max_left_op++;
            } else if (s[i] == ')') {
                min_left_op--;
                max_left_op--;
            } else {
                min_left_op--;
                max_left_op++;
            }
            // never have less than 0 open left brackets
            if (max_left_op < 0) {
                return false;
            }
            min_left_op = max(min_left_op, 0);
        }
        // check having exactly 0 open left brackets.
        return min_left_op == 0;
    }
};