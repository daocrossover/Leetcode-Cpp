// Description:
// Given two words (beginWord and endWord), and a dictionary's word list,
// find all shortest transformation sequence(s) from beginWord to endWord, such that:

// Only one letter can be changed at a time
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

// Note:
// Return an empty list if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

// Example 1:
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// Output:
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]

// Example 2:
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.


// BFS solution:
// Do BFS of paths instead of words!

#include<vector>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<vector<string>> q; // store every path
        // "words" records all the visited nodes on this level
        // these words will never be visited again after this level 
        // and should be removed from wordList. This is guaranteed
        // by the shortest path.
        unordered_set<string> words; // record words in paths that have been looped
        int level = 1, minLevel = INT_MAX; // level: current path length, minLevel: min path length
        q.push(vector<string> {beginWord});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t.size() > level) {
                // some words in dict are already in the current path
                for (string s : words) {
                    // avoid repetition
                    dict.erase(s);
                }
                words.clear();
                level = t.size();
                if (level > minLevel) break; // if length some path > minLevel, then pruning
            }
            // find next words in wordList by changing
            // each element from 'a' to 'z'
            string end = t.back(); // get the last word of current path
            for (int i = 0; i < end.size(); ++i) {
                string tmp = end;
                for (char c = 'a'; c <= 'z'; ++c) {
                    tmp[i] = c;
                    if (dict.find(tmp) == dict.end())
                        continue;
                    // the replaced new word exists in the dict and added to the words.
                    words.insert(tmp);
                    // produce a new path
                    vector<string> nextPath = t;
                    nextPath.push_back(tmp);
                    if (tmp == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else {
                        q.push(nextPath);
                    }
                }
            }
        }
        return res;
    }
};