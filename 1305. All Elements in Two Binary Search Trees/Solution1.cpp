// Description:
// Given two binary search trees root1 and root2.
// Return a list containing all the integers from both trees sorted in ascending order.

// Example 1:
// Input: root1 = [2,1,4], root2 = [1,0,3]
// Output: [0,1,1,2,3,4]

// Example 2:
// Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
// Output: [-10,0,0,1,2,5,7,10]

// Example 3:
// Input: root1 = [], root2 = [5,1,7,0,2]
// Output: [0,1,2,5,7]

// Example 4:
// Input: root1 = [0,-10,10], root2 = []
// Output: [-10,0,10]

// Example 5:
// Input: root1 = [1,null,8], root2 = [8,1]
// Output: [1,1,8,8]
 
// Constraints:
// 1. Each tree has at most 5000 nodes.
// 2. Each node's value is between [-10^5, 10^5].

// Inorder Traversal + Merge Two Lists

#include <vector>
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
    void inorder(TreeNode* root, vector<int>& l) {
        if (!root) return;
        inorder(root->left, l);
        l.push_back(root->val);
        inorder(root->right, l);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2, res;
        inorder(root1, l1);
        inorder(root2, l2);
        int i = 0, j = 0;
        while (res.size() != l1.size() + l2.size()) {
            if (j == l2.size()) {
                res.push_back(l1[i++]);
            } else if (i == l1.size()) {
                res.push_back(l2[j++]);
            } else {
                res.push_back(l1[i] < l2[j] ? l1[i++] : l2[j++]);
            }
        }
        // Or using merge() function in STL
        // res.resize(t1.size() + t2.size());
        // merge(t1.begin(), t1.end(), t2.begin(), t2.end(), res.begin());
        return res;
    }
};