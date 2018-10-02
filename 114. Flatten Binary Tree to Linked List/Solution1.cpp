// Description:
// Given a binary tree, flatten it to a linked list in-place.

// For example, given the following tree:
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6

// The flattened tree should look like:
// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
//          \
//           6


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                //Find current node's prenode that links to current node's right subtree
                TreeNode* p = cur->left;
                while (p->right)
                    p = p->right;
                p->right = cur->right;
                // replace current node's right subtree with its left substree
                cur->right = cur->left;
                // set current node's left tree to NULL
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};