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


// Categorize by Sorted String
// Hashmap Solution:
// Time Complexity:
// 1. Using sort(): O(NKlogK)
// 2. Using strSort(counting sort): O(NK)
// where N is the length of strs, and K is the maximum length of a string in strs.
// Space Complexity: O(NK), the total information content stored in res.

#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            hash[s].push_back(strs[i]);
        }
        unordered_map<string, vector<string>>::iterator it;
        for (it = hash.begin(); it != hash.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }

    string strSort(string& s) {
        int count[26] = {0}, n = s.length();
        for (int i = 0; i < n; i++)
            count[s[i] - 'a']++;
        int p = 0;
        string t(n, 'a');
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < count[j]; i++)
                t[p++] += j;
        return t;
    } 
};