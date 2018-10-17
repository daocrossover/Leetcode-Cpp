// Description:
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

// Note:
// All given inputs are in lowercase letters a-z.


// Vertical Scanning Solution:
//  compare characters from top to bottom on the same column
// (same character index of the strings) before moving on to the next column.

// Time complexity: O(S), where S is the sum of all characters in all strings.
// In the worst case there will be n equal strings with length m and
// the algorithm performs S = m*n character comparisons.
// Space complexity: O(1). We only used constant extra space.

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].length(); ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != c || i == strs[j].length())
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};