// Level-order Traversal, BFS

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* t = q.front();
                q.pop();
                if (!t->left && !t->right) return depth;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            depth++;
        }
        return depth;
    }
};