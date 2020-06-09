// Bit Manipulation and HashSet Solution:
// Use two bits to represent the character
// A: 00, C: 01, G: 10, T: 11
// Therefore, need 20 bits to represent 10 characters, using int to store is enough

#include<string>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::vector;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() <= 10) {
            return {};
        }
        unordered_set<int> set;
        unordered_set<string> res;
        unordered_map<int, int> hash{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int cur = 0;
        for (int i = 0; i < 9; ++i) {
            cur = cur << 2 | hash[s[i]];
        }
        for (int i = 9; i < s.length(); ++i) {
            // mask: 0x3ffff -> 18 ones
            cur = ((cur & 0x3ffff) << 2) | (hash[s[i]]);
            if (set.find(cur) != set.end()) {
                res.insert(s.substr(i - 9, 10));
            } else {
                set.insert(cur);
            }
        }
        return vector<string>{res.begin(), res.end()};
    }
};