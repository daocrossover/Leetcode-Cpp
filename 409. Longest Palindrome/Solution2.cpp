// HashMap Solution (count table)

#include <string>
using std::string;

class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {0};
        int len = 0;
        for (char c: s) {
            count[c]++;
        }
        for (int i: count) {
            len += i / 2 * 2;
            if (len % 2 == 0 && i % 2 == 1) {
                len++;
            }
        }
        return len;
    }
};