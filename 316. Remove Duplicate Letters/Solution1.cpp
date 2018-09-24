// Description:
// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once.
// You must make sure your result is the smallest in lexicographical order among all possible results.

// Example 1:
// Input: "bcabc"
// Output: "abc"

// Example 2:
// Input: "cbacdcbc"
// Output: "acdb"

#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> visited(26, 0); // true if character is in stack, else false
        vector<int> count(26, 0); // how many of this charaters are remaining
        stack<int> st; // stack of unique charaters
        string res;  
        for (char c : s) count[c - 'a']++;
        for (char c : s) {
            int i = c - 'a';
            count[i]--;
            if (!visited[i]) {
                visited[i] = true;
                while (!st.empty() && count[st.top()] && st.top() > i) {
                    visited[st.top()] = false;
                    st.pop();
                }
                st.push(i);
            }
        }
        
        while (!st.empty()) {
            res = string(1, 'a' + st.top()) + res;
            st.pop();
        }
        return res;
    }
};