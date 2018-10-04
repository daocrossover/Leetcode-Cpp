// Description:
// Given two words (beginWord and endWord), and a dictionary's word list,
// find the length of shortest transformation sequence from beginWord to endWord, such that:

// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

// Example 1:
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Example 2:
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.


// BFS Solution:
#include<string>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        // endWord is not in the wordList, return 0 directly
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        // find the transformation of beginWord and add them to the queue
        addWord(beginWord, wordSet, q);
        int dist = 2;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                string tmp = q.front();
                q.pop();
                if (tmp == endWord) return dist;
                addWord(tmp, wordSet, q);
            }
            dist++;
        }
        return 0;
    }
    
    void addWord(string word, unordered_set<string>& wordSet, queue<string>& q) {
        wordSet.erase(word);
        // check every letter of word
        for (int i = 0; i < word.length(); i ++) {
            char tmp = word[i];
            // change the letter of the word from 'a' to 'z'
            for (int j = 0; j < 26; j ++) {
                word[i] = 'a' + j;
                // new word found in the wordSet
                if (wordSet.find(word) != wordSet.end()) {
                    q.push(word);
                    wordSet.erase(word);
                }
            }
            // recover the word
            word[i] = tmp;
        }
    }
};