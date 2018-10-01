// Iterative Solution, BFS

#include<queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* first = q.front();
            q.pop();
            TreeNode* second = q.front();
            q.pop();
            if (!first && !second) continue;
            if (!first || !second || first->val != second->val) return false;
            q.push(first->left);
            q.push(second->right);
            q.push(first->right);
            q.push(second->left);
        }
        return true;
    }
};