// Description:
// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.

// Example:
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]


// Backtracking Solution:

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        backtrack(res, cur, s, 0);
        return res;
    }
    
    void backtrack(vector<vector<string>>& res, vector<string>& cur, string s, int index) {
        if (index == s.length()) {
            res.push_back(cur);
            return;
        } else {
            // try every length >= 1
            for (int i = 1; i <= s.length(); ++i) {
                // over the boundry, break
                if (index + i > s.length()) break;
                string part = s.substr(index, i);
                // judge whether the part of the s is palindrome
                if (!isPalindrome(part)) continue;
                cur.push_back(part);
                backtrack(res, cur, s, index + i);
                cur.pop_back();
            }
        }
    }
    // judge whether a string is palindrome
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};