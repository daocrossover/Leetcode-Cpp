// Expand Around Center Solution:
// The center of a palindrome can be a letter or in between two letters.
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <string>
using std::string;

class Solution {
public:
    // Iterative Solution
    int countSubstrings(string s) {
        int n = s.size(), count = 0;
        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                count++;
            }
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                count++;
            }
        }
        return count++;
    }

    // Recursive Solution
    int countSubstrings1(string s) {
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