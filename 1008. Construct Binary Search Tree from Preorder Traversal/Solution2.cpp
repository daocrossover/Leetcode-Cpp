// Construct BST directly
// Time Complexity: O(nlogn)

#include<vector>
using std::vector;

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = nullptr;
        for (int i : preorder) {
            root = insertBst(root, i); 
        }
        return root;
    }
    
    TreeNode* insertBst(TreeNode* root, int i){
        if (!root) return new TreeNode(i);
        if (i < root->val) {
            root->left = insertBst(root->left, i);
        } else {
            root->right = insertBst(root->right, i);
        }
        return root;
    }
};