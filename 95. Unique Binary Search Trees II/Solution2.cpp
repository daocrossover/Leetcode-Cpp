// Recursive Solution + DP
// eliminate repeating tree construction:

#include<vector>
#include<string>
#include<unordered_map>
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
    unordered_map<string, vector<TreeNode*>> hash;
    
    vector<TreeNode*> generateTree(int from, int to) {
        vector<TreeNode*> res;
        if (from > to) {
            res.push_back(nullptr);
            return res;
        }
        
        string s = to_string(from) + "-" + to_string(to);
        if (hash.find(s) != hash.end())
            return hash[s];
        
        for (int i = from; i <= to; ++i) {
            vector<TreeNode*> leftTree = generateTree(from, i-1);
            vector<TreeNode*> rightTree = generateTree(i+1, to);
            for (int j = 0; j < leftTree.size(); ++j) {
				for (int k = 0; k < rightTree.size(); ++k) {
					TreeNode* root = new TreeNode(i);
					root->left = leftTree[j];
					root->right = rightTree[k];
					res.push_back(root);
				}
			}
        }
        hash[s] = res;
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generateTree(1, n);
    }
};