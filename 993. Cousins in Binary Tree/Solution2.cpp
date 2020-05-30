// Level-Order Traversal Solution (BFS):

#include<queue>
using std::queue;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) {
            return false;
        }
        TreeNode* parent_x;
        TreeNode* parent_y;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            bool x_found = false, y_found = false;
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->val == x) {
                    x_found = true;
                }
                if (cur->val == y) {
                    y_found = true;
                }
                if (cur->left && cur->right) {
                    if (cur->left->val == x && cur->right->val == y) {
                        return false;
                    }
                    if (cur->left->val == y && cur->right->val == x) {
                        return false;
                    }
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            
            if (x_found && y_found) {
                return true;
            }
        }
        
        return false;
    }
};