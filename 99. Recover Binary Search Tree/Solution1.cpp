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

// In-order Traversal Solution:

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
        // In order traversal to find the two elements
        inorderTraversal(root);
        swap(first->val, second->val);
    }
    
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) return;
        inorderTraversal(root->left);

        /* Start of "do some business" */
        // If first element has not been found, assign it to prevElement
        if (first == nullptr && prev != nullptr && prev->val >= root->val) {
            first = prev;
        }
        // If first element is found, assign the second element to the root
        if (first != nullptr && prev->val >= root->val) {
            second = root;
        }
        prev = root;
        /* End of "do some business" */

        inorderTraversal(root->right);
    }
};