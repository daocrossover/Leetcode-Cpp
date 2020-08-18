// Description:
// There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. 
// You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. 
// Derive the order of letters in this language.

// Example 1:
// Input:
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
// Output: "wertf"

// Example 2:
// Input:
// [
//   "z",
//   "x"
// ]
// Output: "zx"

// Example 3:
// Input:
// [
//   "z",
//   "x",
//   "z"
// ] 
// Output: "" 
// Explanation: The order is invalid, so return "".

// Note:
// 1. You may assume all letters are in lowercase.
// 2. You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
// 3. If the order is invalid, return an empty string.
// 4. There may be multiple valid order of letters, return any one of them is fine.

// Transfer to Graph Problem
// Using Topological Sort
// From example 1, we could construct following sequencing order
// t->f
// w->e
// r->t
// e->r
// Then construct the graph and find the topological sort order, which is the order of letters

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using std::vector;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::queue;
using std::min;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 0) return "";
        unordered_map<char, vector<char>> graph;
        unordered_set<char> letters;
        vector<int> indegree(26);
        queue<char> q;
        string res;
        for (auto w: words) {
            letters.insert(w.begin(), w.end()); // get all letters into set
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            // compare adjacent two words
            int len = min(words[i].size(), words[i + 1].size()), j = 0;
            for (; j < len; ++j) {
                char c1 = words[i][j], c2 = words[i + 1][j];
                if (c1 != c2) {
                    graph[c1].push_back(c2);
                    indegree[c2 - 'a']++;
                    break;
                }
            }
            if (j == len && words[i].size() > words[i + 1].size()) return "";
            // corner case - input: ["wrtkj","wrt"] output: ""
        }
        // topological sort: BFS
        for (char c : letters) {
            if (indegree[c - 'a'] == 0) {
                q.push(c);
            } 
        }
        while (!q.empty()) {
            char t = q.front();
            q.pop();
            res.push_back(t);
            for (char c: graph[t]) {
                if (--indegree[c - 'a'] == 0) {
                    q.push(c);
                }
            }
        }
        return res.size() == letters.size() ? res : "";
    }
};
