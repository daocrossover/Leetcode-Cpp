// Level-order Traversal, Space Complexity: O(n)

#include<queue>
using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            TreeLinkNode* pre = new TreeLinkNode(-1);
            for (int i = 0; i < size; ++i) {
                TreeLinkNode* t = q.front();
                q.pop();
                pre->next = t;
                pre = t;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            pre->next = NULL;
        }
    }
};