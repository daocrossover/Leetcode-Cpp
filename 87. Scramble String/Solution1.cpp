// Description:
// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

// Below is one possible representation of s1 = "great":
//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two children.

// For example, if we choose the node "gr" and swap its two children,
// it produces a scrambled string "rgeat".

//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that "rgeat" is a scrambled string of "great".

// Similarly, if we continue to swap the children of nodes "eat" and "at",
// it produces a scrambled string "rgtae".

//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that "rgtae" is a scrambled string of "great".

// Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

// Example 1:
// Input: s1 = "great", s2 = "rgeat"
// Output: true

// Example 2:
// Input: s1 = "abcde", s2 = "caebd"
// Output: false


// Recursive Solution:

#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int n = s1.length();
        if (s1 == s2) return true;
        unordered_map<char, int> hash;
        // count every letter in the s1 and s2
        // in s1, hash[c]++, in s2, hash[c]--;
        // if the s1 and s2 is scrmable, every value in hash should be 0
        for (int i = 0; i < n; ++i) {
            hash[s1[i]]++;
            hash[s2[i]]--;
        }
        unordered_map<char, int>::iterator it;
        for (it = hash.begin(); it != hash.end(); ++it) {
            if (it->second != 0) return false;
        }
        // try every length(1 to s1.length()-1) to exchange the order of substrings
        for (int i = 1; i < n; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i)))
                return true;
        }
        return false;
    }
};