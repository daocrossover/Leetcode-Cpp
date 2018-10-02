// Description:
// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// Note: A leaf is a node with no children.

// Example:
// Given the below binary tree and sum = 22,
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1

// Return:
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, root, sum);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& cur, TreeNode* root, int sum) {
        if (!root) return;
        cur.push_back(root->val);
        if (root->val == sum && !root->left && !root->right) {
            res.push_back(cur);
        } else {
            dfs(res, cur, root->left, sum - root->val);
            dfs(res, cur, root->right, sum - root->val);
        }
        // pop the root in the end, not in the if-esle
        cur.pop_back();
    }
};