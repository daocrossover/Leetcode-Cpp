// Categorize by Count
// Time Complexity: O(NK)
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
            // no need to sort strs[i],
            // transfer it to a new string containing counting information
            vector<int> count(26);
            string s = "";
            for (char c : strs[i]) count[c - 'a']++;
            for (int i = 0; i < 26; i++) {
                s += '#';
                s += (count[i] + '0');
            }
            hash[s].push_back(strs[i]);
        }
        unordered_map<string, vector<string>>::iterator it;
        for (it = hash.begin(); it != hash.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};