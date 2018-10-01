// Description:
// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as:
// a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

// Example 1:
// Given the following tree [3,9,20,null,null,15,7]:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Return true.

// Example 2:
// Given the following tree [1,2,2,3,3,null,null,4,4]:
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
// Return false.


// The same idea as Maximum Depth of Binary Tree:

#include<algorithm>
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        // difference of depth of the two subtrees of root <= 1
        // root->left is also a height-balanced binary tree
        // root->right is also a height-balanced binary tree
        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return 1 + max(maxLeft, maxRight);
    }
};