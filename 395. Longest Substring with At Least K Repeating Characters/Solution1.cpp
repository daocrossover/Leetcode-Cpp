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

// recursive solution:

#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        unordered_map<char, int> count;
        for (char c : s) ++count[c];
        int mid = 0;
        while (mid < n && count[s[mid]] >= k) ++mid;
        if (mid == n) return n;
        int left = longestSubstring(s.substr(0, mid), k);
        while (mid < n && count[s[mid]] < k) ++mid;
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
    }
};