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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
    
    void dfs(TreeNode* root, vector<int>& res, int level) {
        if (!root) return;
        if (res.size() == level)
            res.push_back(root->val);
        dfs(root->right, res, level + 1);
        dfs(root->left, res, level + 1);
    }
};