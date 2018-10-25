// Description:
// Given a string S and a string T,
// find the minimum window in S which will contain all the characters in T in complexity O(n).

// Example:
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"

// Note:
// 1. If there is no such window in S that covers all characters in T,
// return the empty string "".
// 2. If there is such window, you are guaranteed that
// there will always be only one unique minimum window in S.


// Sliding Window Problem:
// Using Hashmap

#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> letterCnt;
        for (char c : t) letterCnt[c]++;
        int left = 0, cnt = 0, minLen = s.length() + 1;
        for (int right = 0; right < s.length(); ++right) {
            if (--letterCnt[s[right]] >= 0) cnt++;
            while (cnt == t.length()) {
                if (minLen > right - left + 1) {
                    minLen = right - left + 1;
                    res = s.substr(left, minLen);
                }
                if (++letterCnt[s[left]] > 0) cnt--;
                left++;
            }
        }
        return res;
    }
};