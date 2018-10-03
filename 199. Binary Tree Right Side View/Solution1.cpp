// Description:
// Given a binary tree, imagine yourself standing on the right side of it,
// return the values of the nodes you can see ordered from top to bottom.

// Example:
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---


// Reverse Levrl-order Traversal

#include<vector>
#include<queue>
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
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* t = q.front();
                q.pop();
                // add the right most node of every level into the result
                if (i == 0) res.push_back(t->val);
                if (t->right) q.push(t->right);
                if (t->left) q.push(t->left);
            }
        }
        return res;
    }
};