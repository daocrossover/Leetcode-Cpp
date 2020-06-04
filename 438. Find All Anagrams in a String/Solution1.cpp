// Description:
// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
// The order of output does not matter.

// Example 1:
// Input:
// s: "cbaebabacd" p: "abc"
// Output:
// [0, 6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

// Example 2:
// Input:
// s: "abab" p: "ab"
// Output:
// [0, 1, 2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

// Sliding Window Solution:

#include<vector>
#include<string>
using std::vector;
using std::string;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.empty()) return res;
        vector<int> m(26, 0);
        int i = 0, j = 0, count = p.length(), n = s.length();
        for (char c : p) {
            m[c - 'a']++;
        }
        while (i < n) {
            if (m[s[i] - 'a'] > 0) {
                count--;
            }
            m[s[i] - 'a']--;
            i++;
            
            if (count == 0) {
                res.push_back(j);
            }
            
            if (i - j == p.length()) {
                if (m[s[j] - 'a'] >= 0) {
                    count++;
                }
                m[s[j] - 'a']++;
                j++;
            }
        }
        return res;
    }
};