#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> hash;
        vector<string> res = helper(word_set, hash, s);
        return res;
    }
    
    vector<string> helper(unordered_set<string>& word_set, unordered_map<string, vector<string>>& hash, string s) {
        if (hash.find(s) != hash.end()) return hash[s];
        vector<string> res;
        if (word_set.find(s) != word_set.end()) res.push_back(s);
        for (int i = 1; i < s.length(); ++i) {
            string word = s.substr(i);
            if (word_set.find(word) != word_set.end()) {
                string rem = s.substr(0, i);
                vector<string> prev = combine(word, helper(word_set, hash, rem));
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        hash[s] = res; // memorize
        return res;
    }
    
    vector<string> combine(string word, vector<string> prev){
        for (int i = 0; i < prev.size(); ++i) {
            prev[i] += (" " + word);
        }
        return prev;
    }
};