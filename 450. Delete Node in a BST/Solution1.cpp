// Description:
// Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
// Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
// 1. Search for a node to remove.
// 2. If the node is found, delete the node.

// Note: Time complexity should be O(height of tree).

// Example:
// root = [5,3,6,2,4,null,7]
// key = 3
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
//     5
//    / \
//   4   6
//  /     \
// 2       7

// Another valid answer is [5,2,6,null,4,null,7].
//     5
//    / \
//   2   6
//    \   \
//     4   7

// Recursive Solution:
// find the successor of node to be deleted

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
        // node doesn't have left or right - return null
        if (root == nullptr) return nullptr;
        if (key < root->val) {
            // node only has left subtree- return the left subtree
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // node only has right subtree- return the right subtree
            root->right = deleteNode(root->right, key);
        } else {
            // node has both left and right
            if (root->left == nullptr) {
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            } else {
                TreeNode* succ = successor(root); // find the minimum value in the right subtree
                root->val = succ->val; // set that value to the currently found node
                root->right = deleteNode(root->right, root->val); // recursively delete the minimum value in the right subtree
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