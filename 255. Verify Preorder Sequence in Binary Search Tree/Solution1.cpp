// 255. Verify Preorder Sequence in Binary Search Tree
// Description:
// Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
// You may assume each number in the sequence is unique.

// Consider the following binary search tree: 

//      5
//     / \
//    2   6
//   / \
//  1   3

// Example 1:
// Input: [5,2,6,1,3]
// Output: false

// Example 2:
// Input: [5,2,1,3,6]
// Output: true

// Follow up:
// Could you do it using only constant space complexity?

// Stack Solution:
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <stack>
using std::vector;
using std::stack;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int cur_root = INT_MIN;
        stack<int> st;
        for (auto& node : preorder) {
            if (node < cur_root) return false;
            while (!st.empty() && node > st.top()) {
                cur_root = st.top();
                st.pop();
            }
            st.push(node);
        }
        return true;
    }
};