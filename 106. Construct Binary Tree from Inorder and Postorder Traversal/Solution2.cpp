// Using hashmap to record the position of root in the inorder array

#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    unordered_map<int, int> hash;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size()) {
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); ++i) {
            hash[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe) {
        if (ps > pe || is > ie) return nullptr;
        TreeNode* root = new TreeNode(postorder[pe]);
        int pos = hash[postorder[pe]];
        root->left = helper(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
        root->right = helper(inorder, postorder, pos + 1, ie, ps + pos - is, pe - 1);
        return root;
    }
};