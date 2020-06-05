// Description:
// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:
// Input:
// "tree"
// Output:
// "eert"
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

// Example 2:
// Input:
// "cccaaa"
// Output:
// "cccaaa"
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Example 3:
// Input:
// "Aabb"
// Output:
// "bbAa"
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

// Count Sort Solution:

#include<unordered_map>
#include<string>
#include<vector>
using std::unordered_map;
using std::string;
using std::vector;
using std::pair;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (char c: s) {
            m[c]++;
        }
        vector<pair<int, char>> v;
        for (auto &a : m) {
            if (a.second > 0) {
                v.push_back({a.second, a.first});
            }
        }
        sort(v.rbegin(), v.rend()); // reversed order
        string res;
        for (auto &kv : v) {
            res.append(kv.first, kv.second);
        }
        return res;
    }
};