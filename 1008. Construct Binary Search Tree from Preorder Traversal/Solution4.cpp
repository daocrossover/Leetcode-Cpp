// Stack solution:
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<vector>
#include<stack>
using std::vector;
using std::stack;

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]); // first element is the root
        stack<TreeNode*> s;
        s.push(root);
        for (int i = 1; i < preorder.size(); ++i) {
            if (preorder[i] < s.top()->val) {
                // if next value is lesser than current then it's a left child
                s.top()->left = new TreeNode(preorder[i]);
                s.push(s.top()->left);
            } else {
                // it's a right child, but need to check whose right child               
                TreeNode* node;
                while (!s.empty() && s.top()->val < preorder[i]) {
                    node = s.top();
                    s.pop();
                }
                node->right = new TreeNode(preorder[i]); // last popped value is the parent of preorder[i]
                s.push(node->right);   
            }
        }
        return root;
    }
};