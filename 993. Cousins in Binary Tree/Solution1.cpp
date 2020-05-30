// Description:
// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
// Return true if and only if the nodes corresponding to the values x and y are cousins.

// Constraints:
// The number of nodes in the tree will be between 2 and 100.
// Each node has a unique integer value from 1 to 100.

// Preorder Traversal Solution (DFS):

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
private:
    TreeNode* parent_x;
    TreeNode* parent_y;
    int depth_x, depth_y;
    
    void find(TreeNode* node, TreeNode* parent, int x, int y, int d) {
        if (node == nullptr) {
            return;
        }
        if (node->val == x) {
            parent_x = parent;
            depth_x = d;
        }
        if (node->val == y) {
            parent_y = parent;
            depth_y = d;
        }
        find(node->left, node, x, y, d + 1);
        find(node->right, node, x, y, d + 1);
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        find(root, nullptr, x, y, 0);
        return depth_x == depth_y && (parent_x != parent_y);
    }
};