// BFS, Level-order Traversal

#include <vector>
#include <queue>
using std::vector;
using std::queue;

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
        if (root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool need_reverse = false;
        while (!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                int index = need_reverse ? size - 1 - i : i; // add element to specific location
                row[index] = node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            need_reverse = !need_reverse;
            res.push_back(row);
        }
        return res;
    }
};