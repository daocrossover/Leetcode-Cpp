// DFS solution:

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        // determine if ')' need to be removed
        DFS(res, s, 0, 0, vector<char>{'(', ')'});
        return res;
    }
    
    void DFS(vector<string> &res, string s, int last_i, int last_j, vector<char> par) {
        for (int i = last_i, cnt = 0; i < s.size(); ++i) {
            if (s[i] == par[0]) cnt++;
            if (s[i] == par[1]) cnt--;
            if (cnt >= 0) continue;
            // cnt < 0 -> more ')' than '(' in the prefix
            // keep tracking the last removal position to avoid duplicates
            for (int j = last_j; j <= i; ++j) {
                if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1])) {
                    // remove the first ')' in a series of concecutive ')'
                    DFS(res, s.substr(0, j) + s.substr(j+1), i, j, par);
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (par[0] == ')') {
            // check if '(' need to be removed, reuse the code
            DFS(res, s, 0, 0, vector<char>{')', '('});
        } else {
            res.push_back(s);
        }
    }
};