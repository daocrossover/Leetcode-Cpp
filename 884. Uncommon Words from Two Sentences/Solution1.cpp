// Description:
// We are given two sentences A and B. (A sentence is a string of space separated words. 
// Each word consists only of lowercase letters.)
// A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
// Return a list of all uncommon words. 
// You may return the list in any order.

// Example 1:
// Input: A = "this apple is sweet", B = "this apple is sour"
// Output: ["sweet","sour"]

// Example 2:
// Input: A = "apple apple", B = "banana"
// Output: ["banana"]

// Note:
// 1. 0 <= A.length <= 200
// 2. 0 <= B.length <= 200
// 3. A and B both contain only spaces and lowercase letters.

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using std::string;
using std::vector;
using std::istringstream;
using std::unordered_map;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        istringstream str(A + " " + B);
        string word;
        unordered_map<string, int> count;
        while (getline(str, word, ' ')) {
            count[word] += 1;
        }
        vector<string> res;
        for (auto &p: count) {
            if (p.second == 1) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};