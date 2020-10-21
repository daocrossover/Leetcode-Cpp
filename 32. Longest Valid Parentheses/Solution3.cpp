// Two-pass Solution:
// Time Complexity: O(2n) = O(n)
// Space Complexity: O(1)

#include <string>
using std::string;
using std::max;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, n = s.length();
        // check unbalanced expression  when ')' appears too often
        int left = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            // when right > left, expression is unbalanced
            // give up the current length and start again.
            if (left == right) {
                res = max(res, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        // check unbalanced expression  when '(' appears too often
        left = right = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                res = max(res, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return res;
    }
};