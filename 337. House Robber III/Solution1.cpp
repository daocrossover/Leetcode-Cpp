// The thief has found himself a new place for his thievery again.
// There is only one entrance to this area, called the "root."
// Besides the root, each house has one and only one parent house.
// After a tour, the smart thief realized that "all houses in this place forms a binary tree".
// It will automatically contact the police if two directly-linked houses were broken into on the same night.

// Determine the maximum amount of money the thief can rob tonight without alerting the police.

// Example 1:
// Input: [3,2,3,null,3,null,1]
//      3
//     / \
//    2   3
//     \   \ 
//      3   1
// Output: 7 
// Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

// Example 2:
// Input: [3,4,5,1,3,null,1]
//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1
// Output: 9
// Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

// the first element of which denotes the maximum amount of money that can be robbed if root is not robbed,
// while the second element signifies the maximum amount of money robbed if it is robbed.

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
    int rob(TreeNode* root) {
        vector<int> res = robSub(root);
        return max(res[0], res[1]);
    }
    
    vector<int> robSub(TreeNode* root) {
        if (!root) return vector<int>(2, 0);
        vector<int> l = robSub(root->left);
        vector<int> r = robSub(root->right);
        vector<int> res(2, 0);
        res[0] = max(l[0], l[1]) + max(r[0], r[1]);
        res[1] = root->val + l[0] + r[0];
        return res;
    }
};