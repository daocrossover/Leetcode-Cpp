// Description:
// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
// The path must contain at least one node and does not need to go through the root.

// Example 1:
// Input: [1,2,3]
//        1
//       / \
//      2   3
// Output: 6

// Example 2:
// Input: [-10,9,20,null,null,15,7]
//    -10
//    / \
//   9  20
//     /  \
//    15   7
// Output: 42


// Comphrehend the meaning of the path!
// When return to the node 11, maxSum = 7+11+2.
// When return to node 4, we can't choose two paths of node 11, so choose larger one between left and right
// Hence, return value of the dfs is max(left, right) + root->val
//     4
//    / \
//   11 13
//  / \
// 7   2

#include<algorithm>
#include<climits>
using std::max;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* root, int &res) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        int max_single = max(root->val, max(left, right) + root->val);
        int max_top = max(max_single, left + right + root->val);
        res = max(res, max_top);
        return max_single;
    }
};