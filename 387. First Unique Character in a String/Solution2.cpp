// Solution 2: Lookup table

#include<string>
using std::string;

class Solution {
public:
    int firstUniqChar(string s) {
        int dict[26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            dict[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (dict[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};