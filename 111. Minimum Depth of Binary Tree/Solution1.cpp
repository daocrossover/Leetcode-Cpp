// Description:
// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.

// Example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its minimum depth = 2.

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);
        // if depth of some substree is equal to 0, then use the max
        return 1 + (min(minLeft, minRight) ? min(minLeft, minRight) : max(minLeft, minRight));
    }
};