// sorting, space complexity O(n)

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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> list;
        vector<int> vals;
        dfs(root, list, vals);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < list.size(); ++i) {
            list[i]->val = vals[i];
        }
    }
    
    void dfs(TreeNode* root, vector<TreeNode*>& list, vector<int>& vals) {
        if (root == nullptr) return;
        dfs(root->left, list, vals);
        list.push_back(root);
        vals.push_back(root->val);
        dfs(root->right, list, vals);
    }
};