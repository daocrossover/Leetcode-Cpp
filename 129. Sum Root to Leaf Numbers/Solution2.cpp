// BFS Solution:

#include <queue>
using std::queue;
using std::pair;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while (!q.empty()) {
            TreeNode* cur = q.front().first;
            int value = q.front().second;
            q.pop();
            if (!cur->left && !cur->right) sum += value;
            if (cur->left) q.push({cur->left, value * 10 + cur->left->val});
            if (cur->right) q.push({cur->right, value * 10 + cur->right->val});
        }
        return sum;
    }
};