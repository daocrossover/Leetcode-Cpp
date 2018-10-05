// Description:
// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// Example:
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]


// DFS Solution:

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        // corner case:
        if (s.size() < 4 || s.size() > 12) return res;
        dfs(res, s, "", 0, 0);
        return res;
    }
    
    void dfs(vector<string>& res, string s, string cur, int index, int count) {
        if (count > 4) return;
        if (count == 4 && index == s.length()) {
            res.push_back(cur);
            return;
        }
        // every part of ip address is between [0-255], 1 bit to 3 bits
        for (int i = 1; i < 4; ++i) {
            if (index + i > s.length()) break;
            string part = s.substr(index, i);
            // start with '0' or over 255
            if ((part[0] == '0' && part.length() > 1) || (i == 3 && stoi(part) >= 256))
                continue;
            dfs(res, s, cur+part+(count == 3 ? "" : "."), index+i, count+1);
        }
    }
};