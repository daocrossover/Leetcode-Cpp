// Description:
// Given a binary tree
// struct TreeLinkNode {
//   TreeLinkNode *left;
//   TreeLinkNode *right;
//   TreeLinkNode *next;
// }

// Populate each next pointer to point to its next right node.
// If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

// Note:
// You may only use constant extra space.
// Recursive approach is fine, implicit stack space does not count as extra space for this problem.

// Example:
// Given the following binary tree,
//      1
//    /  \
//   2    3
//  / \    \
// 4   5    7

// After calling your function, the tree should look like:
//      1 -> NULL
//    /  \
//   2 -> 3 -> NULL
//  / \    \
// 4-> 5 -> 7 -> NULL

// Level-order Traversal Solution:
// Time Complexity: O(n)
// Space Complexity: O(1)

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *prev = nullptr; // head of the next level
        TreeLinkNode *head = nullptr; // the leading node on the next level
        TreeLinkNode *cur = root;     // current node of current level
        while (cur) {
            // iterate on the current level
            while (cur) {
                // left child
                if (cur->left) {
                    if (prev) {
                        prev->next = cur->left;
                    } else {
                        head = cur->left;
                    }
                    prev = cur->left;
                }
                // right child
                if (cur->right) {
                    if (prev) {
                        prev->next = cur->right;
                    } else {
                        head = cur->right;
                    }
                    prev = cur->right;
                }
                // move to next node
                cur = cur->next;
            }
            // move to next level
            cur = head;
            head = nullptr;
            prev = nullptr;
        }
    }
};