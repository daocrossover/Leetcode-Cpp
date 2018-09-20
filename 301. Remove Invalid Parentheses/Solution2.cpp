// DFS solution:

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        // determine if ')' need to be removed
        DFS(res, s, ')', 0);
        return res;
    }
    
    void DFS(vector<string> &res, string s, char ch, int last) {
        for (int i = 0, cnt = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == ')') {
                s[i] == ch ? ++cnt : --cnt;
            }
            if (cnt <= 0) continue; // valid up to now
            for (int j = last; j <= i; ++j) {
                if (s[j] == ch && (j == last || s[j - 1] != ch)) {
                    // try to remove ch at s[j]
                    DFS(res, s.substr(0, j) + s.substr(j+1), ch, j);
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (ch == ')') {
            // check if '(' need to be removed
            DFS(res, s, '(', 0);
        } else {
            res.push_back(s);
        }
    }
};