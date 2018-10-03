// Description:
// Given a binary tree, return all root-to-leaf paths.

// Note: A leaf is a node with no children.

// Example:
// Input:
//    1
//  /   \
// 2     3
//  \
//   5
// Output: ["1->2->5", "1->3"]
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3

#include<vector>
#include<string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, res, "");
        return res;
    }
    
    void dfs(TreeNode* root, vector<string>& res, string cur) {
        if (!root) return;
        cur += (to_string(root->val) + "->");
        if (!root->left && !root->right) {
            res.push_back(cur.substr(0, cur.length() - 2));
            return;
        }
        dfs(root->left, res, cur);
        dfs(root->right, res, cur);
    }
};