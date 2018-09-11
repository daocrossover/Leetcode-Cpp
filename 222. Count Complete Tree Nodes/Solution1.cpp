// Description:
// Given a complete binary tree, count the number of nodes.
// Note:
// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. 
// It can have between 1 and 2h nodes inclusive at the last level h.

// Example:
// Input: 
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6

// Output: 6

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int count = 0;
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = 0, rightHeight = 0;
        TreeNode *l = root, *r = root;
        while (l) {
            leftHeight++;
            l = l->left;
        }
        while (r) {
            rightHeight++;
            r = r->right;
        }
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};