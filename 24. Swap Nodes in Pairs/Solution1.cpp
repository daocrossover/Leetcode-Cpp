// Description:
// Given a linked list, swap every two adjacent nodes and return its head.

// Example:
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Note:
// Your algorithm should use only constant extra space.
// You may not modify the values in the list's nodes, only nodes itself may be changed.


// Iterative Solution:

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        // the key is adding to dummy head before the head
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy, *p = head, *q = head->next;
        while (cur->next && cur->next->next) {
            ListNode *p = cur->next;
            ListNode *q = cur->next->next;
            p->next = q->next;
            cur->next = q;
            q->next = p;
            cur = cur->next->next;
        }
        return dummy->next;
    }
};