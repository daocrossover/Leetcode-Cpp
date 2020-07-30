// Iterative Solution:

#include <queue>
using std::queue;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        qu.push(p);
        qu.push(q);
        while (!qu.empty()) {
            TreeNode* s = qu.front();
            qu.pop();
            TreeNode* t = qu.front();
            qu.pop();
            if (!s && !t) continue;
            if (!s || !t) return false;
            if (s->val != t->val) return false;
            qu.push(s->left);
            qu.push(t->left);
            qu.push(s->right);
            qu.push(t->right);
        }
        return true;
    }
};