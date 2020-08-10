// Categorize by Count
// Two strings are anagrams if and only if their character counts (respective number of occurrences of each character) are the same.
// Time Complexity: O(NK)
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
            // no need to sort strs[i],
            // transfer it to a new string containing counting information
            vector<int> count(26);
            string key = "";
            for (char c : s) count[c - 'a']++;
            for (int i = 0; i < 26; i++) {
                key += '#';
                key += (count[i] + '0');
            }
            hash[key].push_back(s);
        }
        for (auto kv: hash) {
            res.push_back(kv.second);
        }
        return res;
    }
};