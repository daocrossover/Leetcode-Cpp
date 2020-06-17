// Description:
// Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

// Example 1:
// Input:
// s = "aaabb", k = 3
// Output:
// 3
// The longest substring is "aaa", as 'a' is repeated 3 times.

// Example 2:
// Input:
// s = "ababbc", k = 2
// Output:
// 5
// The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.

// Divide and Conquer Solution:
// Using idx to split the string

#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), idx = 0, res = 0;
        int count[26] = {0};
        for (char c: s) count[c - 'a']++;
        bool is_continuous = true;
        for (int i = 0; i < n; ++i) {
            if (count[s[i] - 'a'] < k) {
                res = max(res, longestSubstring(s.substr(idx, i - idx), k));
                is_continuous = false;
                idx = i + 1;
            }
        }
        return is_continuous ? n : max(res, longestSubstring(s.substr(idx, n - idx), k));
    }
};