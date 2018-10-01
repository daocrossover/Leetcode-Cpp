// Description:
// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1:
// Input:
//     2
//    / \
//   1   3
// Output: true

// Example 2:

//     5
//    / \
//   1   4
//      / \
//     3   6
// Output: false
// Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
//              is 5 but its right child's value is 4.


// Inorder Travesal of Tree:
#include<stack>
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* pre = nullptr;
        if (!root) {
            return true;
        } else {
            while (root || !s.empty()) {
                while (root) {
                    // find the left most children
                    s.push(root);
                    root = root->left;
                }
                // get the top of the stack and do something
                root = s.top();
                s.pop();
                if (pre && root->val <= pre->val)
                    return false;
                pre = root;
                root = root->right;
            }
        }
        return true;
    }
};