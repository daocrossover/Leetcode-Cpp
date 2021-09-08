// Solution 2: Lookup table since s consists of only lowercase English letters.

#include <string>
using std::string;

class Solution {
public:
    int firstUniqChar(string s) {
        int dict[26] = {0};
        for (char c : s) {
            dict[c - 'a']++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (dict[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};