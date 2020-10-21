// Recursion Solution with Memorization
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;
using std::max;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> hash;
        return robSub(root, hash);
    }
    
    int robSub(TreeNode* root, unordered_map<TreeNode*, int>& hash) {
        if (!root) return 0;
        if (hash.find(root) != hash.end()) return hash[root];
        int val = 0;
        if (root->left) {
            val += robSub(root->left->left, hash) + robSub(root->left->right, hash);
        }
        if (root->right) {
            val += robSub(root->right->left, hash) + robSub(root->right->right, hash);
        }
        val = max(val + root->val, robSub(root->left, hash) + robSub(root->right, hash));
        hash[root] = val;
        return val;
    }
};