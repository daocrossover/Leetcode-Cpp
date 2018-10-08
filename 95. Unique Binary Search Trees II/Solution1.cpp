// Description:
// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

// Example:
// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3


// Recursive Solution:

#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTree(int from, int to) {
        vector<TreeNode*> res;
        if (from > to) {
            res.push_back(nullptr); 
        } else if (from == to) {
            res.push_back(new TreeNode(from));
        } else {
            for (int i = from; i <= to; ++i) {
                // node i is the root
                vector<TreeNode*> leftTree = generateTree(from, i-1); // generate left subtrees
                vector<TreeNode*> rightTree = generateTree(i+1, to); // generate right subtrees
                // left tree X right tree
                for (int j = 0; j < leftTree.size(); ++j) {
					for (int k = 0; k < rightTree.size(); ++k) {
						TreeNode* root = new TreeNode(i);
						root->left = leftTree[j];
						root->right = rightTree[k];
						res.push_back(root);
					}
				}
            }
        }
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generateTree(1, n);
    }
};