// Description:
// Implement the StreamChecker class as follows:
// StreamChecker(words): Constructor, init the data structure with the given words.
// query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, 
// including this letter just queried) spell one of the words in the given list.
 
// Example:
// StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
// streamChecker.query('a');          // return false
// streamChecker.query('b');          // return false
// streamChecker.query('c');          // return false
// streamChecker.query('d');          // return true, because 'cd' is in the wordlist
// streamChecker.query('e');          // return false
// streamChecker.query('f');          // return true, because 'f' is in the wordlist
// streamChecker.query('g');          // return false
// streamChecker.query('h');          // return false
// streamChecker.query('i');          // return false
// streamChecker.query('j');          // return false
// streamChecker.query('k');          // return false
// streamChecker.query('l');          // return true, because 'kl' is in the wordlist
 
// Note:
// 1. 1 <= words.length <= 2000
// 2. 1 <= words[i].length <= 2000
// 3. Words will only consist of lowercase English letters.
// 4. Queries will only consist of lowercase English letters.
// 5. The number of queries is at most 40000.

// Trie Solution:

#include <string>
#include <vector>
using std::string;
using std::vector;
using std::max;

class TrieNode {
public:
    TrieNode* children[26];
    bool is_word;
    TrieNode() {
        is_word = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    // reverse insert word
    void insert(string& word) {
        TrieNode* cur = root;
        for (int i = word.size() - 1; i >= 0; --i) {
            int pos = word[i] - 'a';
            if (cur->children[pos] == nullptr) {
                cur->children[pos] = new TrieNode();
            }
            cur = cur->children[pos]; 
        }
        cur->is_word = true;
    }
    
    bool findWord(string& word) {
        TrieNode* cur = root;
        for (int i = word.size() - 1; i >= 0; --i) {
            int pos = word[i] - 'a';
            cur = cur->children[pos];
            if (cur == nullptr) return false;
            if (cur->is_word) return true;
        }
        return false;
    }
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for (string word: words) {
            trie.insert(word);
            max_len = max(max_len, word.length());
        }
    }
    
    bool query(char letter) {
        stream += letter;
        // use longest word length to optimize if the stream is very long
        if (stream.size() > max_len) {
            stream.erase(stream.begin());
        }
        return trie.findWord(stream);
    }
    
private:
    string stream = "";
    Trie trie;
    size_t max_len = 0;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */