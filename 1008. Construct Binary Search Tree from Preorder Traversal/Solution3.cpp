// Lower and upper bound
// Time Complexity: O(n)

#include<vector>
using std::vector;

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
    int index = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstHelper(preorder, INT_MIN , INT_MAX);
        // return bstHelper1(preorder, INT_MAX);
    }
    
    // Lower and upper bound recursively
    TreeNode* bstHelper(vector<int>& preorder, int low, int high) {
        if (index == preorder.size() || preorder[index] < low || preorder[index] > high) {
            return nullptr;
        }
        int val = preorder[index++];
        TreeNode* node = new TreeNode(val);
        node->left = bstHelper(preorder, low, val);
        node->right = bstHelper(preorder, val, high);
        return node;   
    }

    // Upper bound only
    TreeNode* bstHelper1(vector<int>& preorder, int high) {
        if (index == preorder.size() || preorder[index] > high) {
            return nullptr;
        }
        int val = preorder[index++];
        TreeNode* node = new TreeNode(val);
        node->left = bstHelper1(preorder, val);
        node->right = bstHelper1(preorder, high);
        return node;   
    }
};