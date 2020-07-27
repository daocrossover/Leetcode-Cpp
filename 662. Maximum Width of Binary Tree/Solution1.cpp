// Description:
// Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.
// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, 
// where the null nodes between the end-nodes are also counted into the length calculation.
// It is guaranteed that the answer will in the range of 32-bit signed integer.

// Example 1:
// Input: 
//            1
//          /   \
//         3     2
//        / \     \
//       5   3     9 

// Output: 4
// Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

// Example 2:
// Input: 
//           1
//          /  
//         3    
//        / \
//       5   3     

// Output: 2
// Explanation: The maximum width existing in the third level with the length 2 (5,3).

// Example 3:
// Input: 
//           1
//          / \
//         3   2 
//        /        
//       5      

// Output: 2
// Explanation: The maximum width existing in the second level with the length 2 (3,2).

// Example 4:
// Input: 
//           1
//          / \
//         3   2
//        /     \
//       5       9 
//      /         \
//     6           7
// Output: 8
// Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).

// Constraints:
// The given binary tree will have between 1 and 3000 nodes.

// BFS Solution:
// mark the id of left child as parent_id * 2;
// mark the id of right child as parent_id * 2 + 1;
// compare the distance from the left most node with the current max width at every level

#include <queue>
using std::queue;
using std::pair;
using std::make_pair;
using std::max;

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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int max_width = 0;
        queue<pair<TreeNode*, unsigned long long>> q; // unsigned long long to avoid overflow
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            unsigned long long l = q.front().second, r = l; // right started same as left
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left) q.push(make_pair(node->left, 2 * r));
                if (node->right) q.push(make_pair(node->right, 2 * r + 1));
            }
            max_width = max(max_width, (int)(r - l + 1));
        }
        return max_width;
    }
};