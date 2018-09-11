// Decription:
// Design a data structure that supports the following two operations:
// void addWord(word)
// bool search(word)

// search(word) can search a literal word or a regular expression string containing only letters a-z or '.'.
// A '.' means it can represent any one letter.

// Example:
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true

// Note:
// You may assume that all words are consist of lowercase letters a-z.

#include<string>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    int isEnd;
    TrieNode() : isEnd(false) {
        for (int i = 0; i < 26; ++i){
            children[i] = nullptr;
        }
    }
};
    
class WordDictionary {    
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!cur->children[word[i] - 'a']) {
                cur->children[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->children[word[i] - 'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchWord(string word, int index, TrieNode* node) {
        if(index >= word.size()) return node->isEnd;
        if (word[index] != '.') {
            if (node->children[word[index] - 'a'])
                return searchWord(word, index+1, node->children[word[index] - 'a']);
        } else {
            for (int j = 0; j < 26; ++j) {
                if (!node->children[j]) continue;
                if (searchWord(word, index+1, node->children[j])) return true;
            }
        }
        return false;
    }
    
    bool search(string word) {
        return searchWord(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */