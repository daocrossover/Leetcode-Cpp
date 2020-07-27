// DFS Solution:

#include <vector>
using std::vector;
using std::max;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<unsigned long long> lefts; // left most nodes at each level;
        int max_width = 0;
        dfs(root, 1, 0, lefts, max_width);
        return max_width;
    }

private:
    void dfs(TreeNode* node, unsigned long long id, int depth, vector<unsigned long long>& lefts, int& max_width) {
        if (!node) return;
        if (depth >= lefts.size()) lefts.push_back(id);  // add left most node
        max_width = max(max_width, (int)(id - lefts[depth] + 1));
        dfs(node->left, id * 2, depth + 1, lefts, max_width);
        dfs(node->right, id * 2 + 1, depth + 1, lefts, max_width);
    }
};