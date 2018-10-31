// Expand Around Center Solution:
// The center of a palindrome can be a letter or in between two letters.
// Time complexity: O(n^2), Space complexity: O(1)

#include<string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            helper(s, i, i, res);
            helper(s, i, i + 1, res);
        }
        return res;
    }
    
    void helper(string s, int i, int j, int& res) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
            ++res;
        }
    }
};