// Description:
// Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).
// If two nodes are in the same row and column, the order should be from left to right.

// Examples 1:
// Input: [3,9,20,null,null,15,7]
//    3
//   /\
//  /  \
//  9  20
//     /\
//    /  \
//   15   7 
// Output:
// [
//   [9],
//   [3,15],
//   [20],
//   [7]
// ]

// Examples 2:
// Input: [3,9,8,4,0,1,7]
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7 
// Output:
// [
//   [4],
//   [9],
//   [3,0,1],
//   [8],
//   [7]
// ]

// Examples 3:
// Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)
//      3
//     /\
//    /  \
//    9   8
//   /\  /\
//  /  \/  \
//  4  01   7
//     /\
//    /  \
//    5   2
// Output:
// [
//   [4],
//   [9,5],
//   [3,0,1],
//   [8,2],
//   [7]
// ]

// map is ordered

#include <vector>
#include <map>
#include <queue>
using std::vector;
using std::map;
using std::queue;
using std::pair;

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        map<int, vector<int>> nodes;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t.first;
            TreeNode* node = t.second;
            nodes[x].push_back(node->val);
            if (node->left) q.push({x - 1, node->left});
            if (node->right) q.push({x + 1, node->right});
        }
        for (auto x: nodes) {
            res.push_back(x.second);
        }
        return res;
    }
};