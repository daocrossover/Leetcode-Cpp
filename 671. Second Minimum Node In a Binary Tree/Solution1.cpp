#include<algorithm>
using std::max;
using std::min;

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
private:
    int helper(TreeNode* node, int first) {
        if (!node) return -1;
        if (node->val != first) return node->val;
        int l = helper(node->left, first);
        int r = helper(node->right, first);
        return (l == -1 || r == -1) ? max(l, r) : min(l, r);
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        return helper(root, root->val);
    }
};