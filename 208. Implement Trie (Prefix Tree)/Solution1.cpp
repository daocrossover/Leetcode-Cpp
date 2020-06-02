// Description:
// Implement a trie with insert, search, and startsWith methods.

// Example:
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");   
// trie.search("app");     // returns true

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

#include<string>
using std::string;

class TrieNode {
public:
    static const int SIZE = 26; 
    bool isEnd = false;
    TrieNode* children[SIZE];
    TrieNode() {
        for (int i = 0; i < SIZE; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            if (cur->children[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.length(); ++i) {
            char c = prefix[i];
            if (cur->children[c - 'a'] == nullptr) {
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */