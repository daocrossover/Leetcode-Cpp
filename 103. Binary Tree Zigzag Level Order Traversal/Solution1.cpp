// Description:
// Given a binary tree, return the zigzag level order traversal of its nodes' values.
// (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(res, root, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, TreeNode* root, int level) {
        if (!root) return;
        if (res.size() == level) res.push_back(vector<int>());
        if (level % 2) {
            // add to the vector at the beginning at odd level 
            res[level].insert(res[level].begin(), root->val);
        } else {
            // add to the vector at the back at even level
            res[level].push_back(root->val);
        }
        dfs(res, root->left, level + 1);
        dfs(res, root->right, level + 1);
    }
};