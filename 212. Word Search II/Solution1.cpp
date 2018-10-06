// Description:
// Given a 2D board and a list of words from the dictionary, find all words in the board.

// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once in a word.

// Example:
// Input: 
// words = ["oath","pea","eat","rain"] and board =
// [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// Output: ["eat","oath"]

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.


// Trie Tree + DFS:

#include<string>
#include<vector>
using namespace std;

class Solution {
    // Trie node structure:
    class TrieNode {
    public:
        TrieNode* children[26];
        // use the last node of the tree to store the word
        string word;
        TrieNode() {
            word = "";
            for (auto &a : children) a = NULL;
        }
    };
    // Trie =structure:
    class Trie {
    public:
        TrieNode *root;
        
        Trie() {
            root = new TrieNode();
        }
        
        void insert(string str) {
            TrieNode *p = root;
            for (char c : str) {
                int i = c - 'a';
                if (!p->children[i]) p->children[i] = new TrieNode();
                p = p->children[i];
            }
            p->word = str;
        }
    };
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        // do not visit the same cell
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (string s: words) T.insert(s);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, T.root, visited, res);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<vector<bool>>& visited, vector<string>& res) {
        char c = board[i][j];
        if (visited[i][j] == true || p->children[c-'a'] == NULL) return;
        p = p->children[c-'a'];
        if (p->word != "") {
            // found one
            res.push_back(p->word);
            // de-duplicate
            p->word = "";
        }
        visited[i][j] = true;
        if (i > 0) dfs(board, i - 1, j, p, visited, res);
        if (j > 0) dfs(board, i, j - 1, p, visited, res);
        if (i < board.size() - 1) dfs(board, i + 1, j, p, visited, res); 
        if (j < board[0].size() - 1) dfs(board, i, j + 1, p, visited, res); 
        visited[i][j] = false;
    }
};