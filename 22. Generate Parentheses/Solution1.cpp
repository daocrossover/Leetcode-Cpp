// Description:
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
    
    void backtrack(vector<string>& res, string cur, int open, int close, int n) {
        if (cur.length() == 2 * n) {
            res.push_back(cur);
            return;
        }
        
        if (open < n) backtrack(res, cur + '(', open + 1, close, n);
        if (close < open) backtrack(res, cur + ')', open, close + 1, n);
    }
};
