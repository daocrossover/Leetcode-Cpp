// 49. Group Anagrams
// Description:
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

// Constraints:
// 1 <= strs.length <= 10^4
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

// Hashmap + Sort Solution: Categorize by Sorted String
// Time Complexity: O(NKlogK) (using sort())
// where N is the length of strs, and K is the maximum length of a string in strs.
// Space Complexity: O(NK), the total information content stored in res.

#include <vector>
#include <string>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;
        for (string s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            hash[key].push_back(s);
        }
        for (auto kv: hash) {
            res.push_back(kv.second);
        }
        return res;
    }
};