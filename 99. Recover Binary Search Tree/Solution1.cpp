// Description:
// Two elements of a binary search tree (BST) are swapped by mistake.

// Recover the tree without changing its structure.

// Example 1:
// Input: [1,3,null,null,2]

//    1
//   /
//  3
//   \
//    2

// Output: [3,1,null,null,2]

//    3
//   /
//  1
//   \
//    2

// Example 2:
// Input: [3,1,4,null,null,2]

//   3
//  / \
// 1   4
//    /
//   2

// Output: [2,1,4,null,null,3]

//   2
//  / \
// 1   4
//    /
//   3

// Follow up:
// A solution using O(n) space is pretty straight forward.
// Could you devise a constant space solution?

// in-order traversal solution:

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
    TreeNode *first, *second, *prev;
public:
    void recoverTree(TreeNode* root) {
        first = nullptr;
        second = nullptr;
        prev = nullptr;
        dfs(root);
        swap(first->val, second->val);
    }
    
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        if (first == nullptr && prev != nullptr && prev->val >= root->val) {
            first = prev;
        }
        if (first != nullptr && prev->val >= root->val) {
            second = root;
        }
        prev = root;
        dfs(root->right);
    }
};