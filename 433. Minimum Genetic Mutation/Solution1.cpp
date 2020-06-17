// Description:
// A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".
// Suppose we need to investigate about a mutation (mutation from "start" to "end"), 
// where ONE mutation is defined as ONE single character changed in the gene string.

// For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
// Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.
// Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". 
// If there is no such a mutation, return -1.

// Note:
// 1. Starting point is assumed to be valid, so it might not be included in the bank.
// 2. If multiple mutations are needed, all mutations during in the sequence must be valid.
// 3. You may assume start and end string is not the same.

// Example 1:
// start: "AACCGGTT"
// end:   "AACCGGTA"
// bank: ["AACCGGTA"]
// return: 1

// Example 2:
// start: "AACCGGTT"
// end:   "AAACGGTA"
// bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
// return: 2

// Example 3:
// start: "AAAAACCC"
// end:   "AACCCCCC"
// bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
// return: 3

// BFS + Backtracking Solution:

#include <string>
#include <unordered_set>
#include <queue>
#include <vector>
using std::string;
using std::unordered_set;
using std::queue;
using std::vector;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        string genes = "ACGT";
        unordered_set<string> bank_set(bank.begin(), bank.end());
        unordered_set<string> visited; // used to avoid duplicates
        queue<string> q;
        int times = 0;
        q.push(start);
        visited.insert(start);
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                string cur = q.front();
                q.pop();
                if (cur == end) {
                    return times;
                }
                for (int i = 0; i < cur.length(); ++i) {
                    // backtracking
                    char old = cur[i];
                    for (char g: genes) {
                        cur[i] = g;
                        string next(cur);
                        if (!visited.count(next) && bank_set.count(next)) {
                            visited.insert(next);
                            q.push(next);
                        }
                    }
                    cur[i] = old;
                }
            }
            times++;
        }
        return -1;
    }
};