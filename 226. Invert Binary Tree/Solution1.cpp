// Invert a binary tree.

// Example:
// Input:
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9

// Output:
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1

// Recursive Solution:

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        TreeNode* left_tree = invertTree(root->left);
        TreeNode* right_tree = invertTree(root->right);
        root->left = right_tree;
        root->right = left_tree;
        return root;
    }
};