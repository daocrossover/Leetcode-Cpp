// Using Stack:

#include<stack>
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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *prev = NULL, *cur = NULL;
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            if (prev != NULL) {
                // link the left node to the right subtree of prev
                // set the left subtree of prev to NULL
                prev->right = cur;
                prev->left = NULL;
            }
            // visit left node first
            if (cur->right != NULL) s.push(cur->right);
            if (cur->left != NULL) s.push(cur->left);
            prev = cur;
        }
        // set the right substree of cur to NULL in the end
        cur->right = NULL;
    }
};