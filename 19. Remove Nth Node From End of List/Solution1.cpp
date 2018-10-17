// Description:
// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:
// Given linked list: 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.

// Note:
// Given n will always be valid.

// Follow up:
// Could you do this in one pass?


// One Pass Solution:

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *q = head;
        // the second ptr goes n step;
        while (n > 0) {
            q = q->next;
            n--;
        }
        // remove the head
        if (!q) return head->next;
        ListNode *pre = nullptr;
        // the first ptr and second ptr goes further until
        // the second ptr is NULL
        while (q) {
            pre = p;
            p = p->next;
            q = q->next;
        }
        // remove the first ptr
        pre->next = p->next;
        p->next = nullptr;
        return head;
    }
};