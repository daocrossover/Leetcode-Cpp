// Description:
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

// Note: A leaf is a node with no children.

// Example:
// Given the below binary tree and sum = 22,
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \      \
// 7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        bool flag1 = false, flag2 = false;
        if (root->val == sum && !root->left && !root->right) {
            return true;
        } else {
            if (root->left) flag1 = hasPathSum(root->left, sum - root->val);
            if (root->right) flag2 = hasPathSum(root->right, sum - root->val);
        }
        return flag1 || flag2;
    }
};