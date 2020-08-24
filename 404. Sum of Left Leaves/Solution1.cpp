// Description:
// Find the sum of all left leaves in a given binary tree.

// Example:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        dfs(root, false);
        return res;
    }

private:
    int res = 0;
    
    void dfs(TreeNode* node, bool is_left) {
        if (!node->left && !node->right && is_left) {
            res += node->val;
        }
        if (node->left) dfs(node->left, true);
        if (node->right) dfs(node->right, false);
    }
};