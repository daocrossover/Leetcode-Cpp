// Description:
// Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 ≤ i ≤ j < n.

// Follow up: Could you do this in O(n) runtime?

// Example 1:
// Input: nums = [3,10,5,25,2,8]
// Output: 28
// Explanation: The maximum result is 5 XOR 25 = 28.

// Example 2:
// Input: nums = [0]
// Output: 0

// Example 3:
// Input: nums = [2,4]
// Output: 6

// Example 4:
// Input: nums = [8,10,2]
// Output: 10

// Example 5:
// Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
// Output: 127
 
// Constraints:
// 1. 1 <= nums.length <= 2 * 104
// 2. 0 <= nums[i] <= 231 - 1

// Trie Solution:
// Time Complexity: O(n)

#include <vector>
using std::vector;
using std::max;

class TrieNode {
public:
    TrieNode* children[2];
    int num;
    
    TrieNode() {
        num = 0;
        for (int i = 0; i < 2; ++i) {
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
    
    // get each bit of num and insert into the trie
    void insert(int num) {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (cur->children[bit] == nullptr) {
                cur->children[bit] = new TrieNode();
            }
            cur = cur->children[bit];
        }
        cur->num = num;
    }
    
    // for each num, find the complement of num in the trie possibly
    int find(int num) {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (cur->children[1 - bit]) {
                cur = cur->children[1 - bit];
            } else {
                cur = cur->children[bit];
            }
        }
        return cur->num;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root = new Trie();
        for (int num: nums) {
            root->insert(num);
        }
        int max_xor = INT_MIN;
        for (int num: nums) {
            int n = root->find(num);
            max_xor = max(max_xor, n ^ num);
        }
        return max_xor;
    }
};