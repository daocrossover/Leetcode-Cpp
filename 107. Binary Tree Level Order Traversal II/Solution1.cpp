// Description:
// Given a binary tree, return the bottom-up level order traversal of its nodes' values.
// (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]


// DFS Solution:

#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        DFS(root, 0);
        return vector<vector<int>>(res.rbegin(), res.rend());
    }

    void DFS(TreeNode* root, int level) {
        if (root == NULL) return;
        if (level == res.size()) {
            // The level does not exist in output
            // Create a new level
            res.push_back(vector<int>());
        }
        res[level].push_back(root->val); // Add the current value to its level
        DFS(root->left, level+1); // Go to the next level
        DFS(root->right,level+1);
    }
};