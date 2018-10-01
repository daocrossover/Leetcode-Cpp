// Description:
// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// Recursive Solution:

#include<vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
        if (preLeft > preRight) return NULL;
        TreeNode* root = new TreeNode(preorder[preLeft]);
        int i;
        // find the root of the tree in the inorder
        for (i = inLeft; i <= inRight; ++i) {
            if (inorder[i] == root->val) break;
        }
        //           root   root->left  root->right
        // preorder = [3,       9,       20,15,7]
        //        root->left   root    root->right
        // inorder  = [9,       3,       15,20,7]
        root->left = build(preorder, inorder, preLeft + 1, preLeft + i - inLeft, inLeft, i - 1);
        root->right = build(preorder, inorder, preLeft + i - inLeft + 1, preRight, i + 1, inRight);
        return root;
    }
};