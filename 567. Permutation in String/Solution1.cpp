// Description:
// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
// In other words, one of the first string's permutations is the substring of the second string.

// Example 1:
// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
 
// Constraints:
// 1. The input strings only contain lower case letters.
// 2. The length of both given strings is in range [1, 10,000].

// The idea is the same as the problem 438
// Sliding Window Solution:

#include<vector>
#include<string>
using std::vector;
using std::string;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> m(26, 0);
        int i = 0, j = 0, count = s1.length(), n = s2.length();
        for (char c : s1) {
            m[c - 'a']++;
        }
        while (i < n) {
            if (m[s2[i] - 'a'] > 0) {
                count--;
            }
            m[s2[i] - 'a']--;
            i++;
            
            if (count == 0) {
                return true;
            }
            
            if (i - j == s1.length()) {
                if (m[s2[j] - 'a'] >= 0) {
                    count++;
                }
                m[s2[j] - 'a']++;
                j++;
            }
        }
        return false;
    }
};