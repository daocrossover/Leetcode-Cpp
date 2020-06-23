// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // find the height h of the whole tree. 
    int height(TreeNode* root) {
        return root ? 1 + height(root->left) : -1;
    }

public:
    int countNodes(TreeNode* root) {
        int nodes = 0, h = height(root);
        while (root) {
            if (height(root->right) == h - 1) {
                // the left and right subtree have the same height
                // the left subtree is a full tree of height h-1
                nodes += 1 << h; // 2^h - 1 nodes of the left subtree plus the root node
                root = root->right;
            } else {
                // the right subtree is a full tree of height h-2.
                nodes += 1 << (h - 1); // 2^(h-1) - 1 nodes of the right subtree plus the root node
                root = root->left;
            }
            h--;
        }
        return nodes;
    }
};