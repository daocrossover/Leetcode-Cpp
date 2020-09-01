// Optimization to Solution1 for two children case:

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            } else {
                // since successor always left child of its parent, make successor's right child as left of its parent. 
                // if there is no succ, then assign succ->right to succ_parent->right
                TreeNode* succ_parent = root;
                TreeNode* succ = root->right;
                while (succ->left != nullptr){
                    succ_parent = succ;
                    succ = succ->left;
                }
                if (succ_parent != root) {
                    succ_parent->left = succ->right;
                } else {
                    succ_parent->right = succ->right;
                }
                root->val = succ->val;
            }
        }
        return root;
    }

private:
    TreeNode* successor(TreeNode* node) {
        node = node->right;
        while (node->left != nullptr){
            node = node->left;
        }
        return node;
    }
};