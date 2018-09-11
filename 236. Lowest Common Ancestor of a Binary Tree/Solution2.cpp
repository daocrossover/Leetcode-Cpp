// iterative solution:

#include<unordered_map>
#include<queue>
#include<set>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> qu;
        parent.insert(make_pair(root, nullptr));
        qu.push(root);
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* node = qu.front();
            qu.pop();
            if (node != nullptr) {
                parent.insert(make_pair(node->left, node));
                parent.insert(make_pair(node->right, node));
                qu.push(node->left);
                qu.push(node->right);
            }
        }
        set<TreeNode*> s;
        while (p != nullptr) {
            s.insert(p);
            p = parent[p];
        }
        while (s.find(q) == s.end()) {
            q = parent[q];
        }
        return q;
    }
};