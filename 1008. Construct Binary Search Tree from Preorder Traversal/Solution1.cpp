// Description:
// Return the root node of a binary search tree that matches the given preorder traversal.
// (Recall that a binary search tree is a binary tree where for every node, any descendant of node.
// left has a value < node.val, and any descendant of node.right has a value > node.val.
// Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)
// It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

// Example 1:
// Input: [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]
//        8
//       / \
//      5   10
//     / \   \
//    1   7   12

// Constraints:
// 1 <= preorder.length <= 100
// 1 <= preorder[i] <= 10^8
// The values of preorder are distinct

// Construct left subtree and right subtree recursively
// Time Complexity: O(n^2)

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
        return build(preorder, 0, preorder.size());
    }
    
    TreeNode* build(vector<int>& preorder, int start, int end) {
        if (start >= end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[start]);
        int mid = start;
        while (mid < end && preorder[mid] <= root->val) {
            mid++;
        }
        root->left = build(preorder, start + 1, mid);
        root->right = build(preorder, mid, end);
        return root;
    }
};