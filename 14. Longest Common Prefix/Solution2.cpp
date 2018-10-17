// Horizontal Scanning Solution:
// LCP(S1…Sn) = LCP(LCP(LCP(S1,S2),S3),…Sn)

// Time complexity: O(S), where S is the sum of all characters in all strings.
// In the worst case all n strings are the same. 
// The algorithm compares the string S1 with the other strings [S2...Sn]
// There are S character comparisons, where S is the sum of all characters in the input array.
// Space complexity: O(1)

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            string s = strs[i];
            if (s.length() == 0) return "";
            int j = 0;
            for (; j < res.length() && j < s.length(); ++j) {
                if (s[j] != res[j])
                    break;
            }
            // construct new common prefix
            res = res.substr(0, j);
        }
        return res;
    }
};
