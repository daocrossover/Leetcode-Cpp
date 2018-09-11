// recursive solution 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int count = 0;
    int res = 0;
public:
    int kthSmallest(TreeNode *root, int k) {
        helper(root, k);
        return res;
    }

    void helper(TreeNode *root, int k) {
        if (root == nullptr) return;
        
        helper(root->left, k);
        if (++count == k) {
            res = root->val;
            return;
        }
        helper(root->right, k);
    }
};
