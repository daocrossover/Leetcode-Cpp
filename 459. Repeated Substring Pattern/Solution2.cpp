// Solution2: Brute force
// The length of the repeating substring must be a divisor of the length of the input string
// try each divisor from len / 2
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <string>
using std::string;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for (int i = len / 2; i >= 1; --i) {
            if (len % i == 0) {
                int j = 0;
                // check every possible repeated substrings
                while (j < len && s[j] == s[j % i]) {
                    j++;
                }
                if (j == len) return true;
                /* Space Complexity: O(n)
                    int num = len / i; // number of repeated substrings
                    string sub_s = s.substr(0, i);
                    int j;
                    // check every possible repeated substrings
                    for (j = 1; j < num; ++j) {
                        if (sub_s != s.substr(j * i, i)) {
                            break;
                        }
                    }
                    if (j == num) return true;
                */
            }
        }
        return false;
    }
};