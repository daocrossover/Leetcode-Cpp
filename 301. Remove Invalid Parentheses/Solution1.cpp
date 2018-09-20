// Description:
// Remove the minimum number of invalid parentheses in order to make the input string valid.
// Return all possible results.

// Note: The input string may contain letters other than the parentheses ( and ).

// Example 1:
// Input: "()())()"
// Output: ["()()()", "(())()"]

// Example 2:
// Input: "(a)())()"
// Output: ["(a)()()", "(a())()"]

// Example 3:
// Input: ")("
// Output: [""]

// BFS solution:

#include<vector>
#include<queue>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        unordered_set<string> visited;
        bool found = false;
        q.push(s);
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            if (isValid(str)) {
                found = true;
                res.push_back(str);
            }
            if (found) continue;
            for (int i = 0; i < str.length(); ++i) {
                if (str[i] != '(' && str[i] != ')') {
                    continue;
                }
                string tmp = str.substr(0, i) + str.substr(i+1);
                if (visited.find(tmp) == visited.end()) {
                    q.push(tmp);
                    visited.insert(tmp);
                }
            }
        }
        return res;
    }
    
    bool isValid(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') count++;
            if (s[i] == ')' && count-- == 0) return false;
        }
        return count == 0;
    }
};