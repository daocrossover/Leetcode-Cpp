// Description:
// Design an Iterator class, which has:
// A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
// A function next() that returns the next combination of length combinationLength in lexicographical order.
// A function hasNext() that returns True if and only if there exists a next combination.
 
// Example:
// CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.
// iterator.next(); // returns "ab"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "ac"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "bc"
// iterator.hasNext(); // returns false
 
// Constraints:
// 1. 1 <= combinationLength <= characters.length <= 15
// 2. There will be at most 10^4 function calls per test.
// 3. It's guaranteed that all calls of the function next are valid.

// Generate all combinations first
// Using queue to retrieve

#include <string>
#include <queue>
using std::string;
using std::queue;

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        string cur = "";
        generate(combinationLength, 0, characters, cur);
    }
    
    string next() {
        string t = q.front();
        q.pop();
        return t;
    }
    
    bool hasNext() {
        return !q.empty();
    }
    
private:
    queue<string> q;
    
    void generate(int len, int start, string s, string& cur) {
        if (len == 0) {
            q.push(cur);
            return;
        }
        for (int i = start; i <= s.length() - len; ++i) {
            cur.push_back(s[i]);
            generate(len - 1, i + 1, s, cur);
            cur.pop_back();
        }
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */