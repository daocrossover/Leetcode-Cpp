// Description:
// All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
// When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
// Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

// Example:
// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: ["AAAAACCCCC", "CCCCCAAAAA"]

// HashSet Solution:

#include<string>
#include<unordered_set>
#include<vector>
using std::string;
using std::unordered_set;
using std::vector;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) {
            return {};
        }
        unordered_set<string> set, res;
        for (int i = 0; i < s.length() - 9; ++i) {
            string t = s.substr(i, 10);
            if (set.find(t) != set.end()) {
                res.insert(t);
            } else {
                set.insert(t);
            }
        }
        return vector<string>{res.begin(), res.end()};
    }
};
