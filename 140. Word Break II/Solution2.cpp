#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> hash;
        vector<string> res = helper(wordSet, hash, s);
        return res;
    }
    
    vector<string> helper(unordered_set<string>& wordDict, unordered_map<string, vector<string>>& hash, string s) {
        if (hash.count(s)) return hash[s];
        vector<string> res;
        if (wordDict.count(s)) res.push_back(s);
        for (int i = 1; i < s.length(); ++i) {
            string word = s.substr(i);
            if (wordDict.count(word)) {
                string rem = s.substr(0, i);
                vector<string> prev = combine(word, helper(wordDict, hash, rem));
                res.insert(res.end(), prev.begin(), prev.end());
            }
        }
        hash[s] = res; //memorize
        return res;
    }
    
    vector<string> combine(string word, vector<string> prev){
        for (int i = 0; i < prev.size(); ++i) {
            prev[i] += (" " + word);
        }
        return prev;
    }
};