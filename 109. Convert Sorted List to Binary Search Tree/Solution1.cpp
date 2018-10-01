// Description:
// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree
// in which the depth of the two subtrees of every node never differ by more than 1.

// Example:
// Given the sorted linked list: [-10,-3,0,5,9],
// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//       0
//      / \
//    -3   9
//    /   /
//  -10  5


// Recursive Solution:

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, nullptr);
    }
    
    TreeNode* build(ListNode* head, ListNode* tail) {
        ListNode *slow = head, *fast = head;
        if (head == tail) return nullptr;
        // find the mid node in singly-linked list: fast && slow
        while (fast != tail && fast->next != tail) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // the same as the operations in array
        TreeNode* root = new TreeNode(slow->val);
        root->left = build(head, slow);
        root->right = build(slow->next, tail);
        return root;
    }
};
