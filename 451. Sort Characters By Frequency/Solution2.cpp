// Create comparison lambda function:

#include<unordered_map>
#include<string>
using std::unordered_map;
using std::string;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        // should include '&'
        sort(s.begin(), s.end(), [&](char a, char b){
            return m[a] > m[b] || (m[a] == m[b] && a < b);
        });
        return s;
    }
};