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


// (1) On the first level, there's only one string which is the input string s, let's say the length of it is n, to check whether it's valid, we need O(n) time.
// (2) On the second level, we remove one ( or ) from the first level, so there are C(n, n-1) new strings,
// each of them has n-1 characters, and for each string, we need to check whether it's valid or not, thus the total time complexity on this level is (n-1) x C(n, n-1).
// (3) Come to the third level, total time complexity is (n-2) x C(n, n-2), so on and so forth...

// Finally we have this formula:
// T(n) = n x C(n, n) + (n-1) x C(n, n-1) + ... + 1 x C(n, 1) = n x 2^(n-1).

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
                // check if a state is valid,
                // if found valid ones on the current level, put them to the final result list
                found = true;
                res.push_back(str);
            }
            if (found) continue;
            // generate all possible states
            for (int i = 0; i < str.length(); ++i) {
                if (str[i] != '(' && str[i] != ')') {
                    continue;
                }
                // only remove one '(' or ')'
                string tmp = str.substr(0, i) + str.substr(i+1);
                if (visited.find(tmp) == visited.end()) {
                    // for each state, if it's not visited, add it to the queue
                    q.push(tmp);
                    visited.insert(tmp);
                }
            }
        }
        return res;
    }
    
    // checks if string s contains valid parantheses
    bool isValid(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') count++;
            if (s[i] == ')' && count-- == 0) return false;
        }
        // the number of '(' and ')' in the s are the same if count == 0
        return count == 0;
    }
};