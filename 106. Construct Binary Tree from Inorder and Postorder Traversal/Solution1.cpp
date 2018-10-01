// Description:
// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }
    
    TreeNode* build(int postStart, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder) {
        if(postStart > postorder.size() - 1 || inStart > inEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postStart]);
        // find the root of the tree in the inorder
        int i = -1;
        for(i = inStart; i <= inEnd; i ++) {
            if(inorder[i] == root->val) {
                break;
            }
        }
        //         root->left   root->right    root
        // postorder = [9,        15,7,20,       3]
        //         root->left   root     root->right
        // inorder   = [9,        3,       15,20,7]
        root->left = build(postStart - inEnd + i - 1, inStart, i - 1, inorder, postorder);
        root->right = build(postStart - 1, i + 1, inEnd, inorder, postorder);
        return root;
    }
};
