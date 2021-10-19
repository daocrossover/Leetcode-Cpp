// 524. Longest Word in Dictionary through Deleting
// Description:
// Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. 
// If there is more than one possible result, return the longest word with the smallest lexicographical order. 
// If there is no possible result, return the empty string.

// Example 1:
// Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
// Output: "apple"

// Example 2:
// Input: s = "abpcplea", dictionary = ["a","b","c"]
// Output: "a"

// Constraints:
// 1 <= s.length <= 1000
// 1 <= dictionary.length <= 1000
// 1 <= dictionary[i].length <= 1000
// s and dictionary[i] consist of lowercase English letters.

// Checking Subsequence 
// Time Complexity: O(nk) 
// where n is the length of string s and k is the number of words in the dictionary.

#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for (string d : dictionary) {
            int i = 0, n = d.length();
            for (char c : s) {
                if (c == d[i] && i < n) {
                    i++;
                }
                if (i == n) {
                    break;
                }
            }
            if (i == n && n >= res.length()) {
                if (n > res.length() || d < res) {
                    res = d; 
                }
            }
        }
        return res;
    }
};