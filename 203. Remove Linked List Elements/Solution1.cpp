// Description:
// Remove all elements from a linked list of integers that have value val.

// Example:
// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5

// Iterative Solution:

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
            } else {
                pre = pre->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};