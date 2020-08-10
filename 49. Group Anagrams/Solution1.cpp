// Description:
// Given an array of strings, group anagrams together.

// Example:
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]

// Note:
// All inputs will be in lowercase.
// The order of your output does not matter.

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