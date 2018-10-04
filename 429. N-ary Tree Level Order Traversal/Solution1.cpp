// Description:
// Given an n-ary tree, return the level order traversal of its nodes' values.
// (ie, from left to right, level by level).

// For example, given a 3-ary tree:
// We should return its level order traversal:
// [
//      [1],
//      [3,2,4],
//      [5,6]
// ]

// Note:
// The depth of the tree is at most 1000.
// The total number of nodes is at most 5000.

#include<vector>
#include<queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val = 0;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for (int j = 0; j < node->children.size(); ++j) {
                    q.push(node->children[j]);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};