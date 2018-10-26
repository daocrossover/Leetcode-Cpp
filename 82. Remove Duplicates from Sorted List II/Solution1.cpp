// Description:
// Given a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list.

// Example 1:
// Input: 1->2->3->3->4->4->5
// Output: 1->2->5

// Example 2:
// Input: 1->1->1->2->3
// Output: 2->3


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = dummy;
        while (p->next && p->next->next) {
            if (p->next->val == p->next->next->val) {
                // escape the duplicates
                int dup = p->next->val;
                while (p->next && p->next->val == dup) {
                    p->next = p->next->next;
                }
            } else {
                p = p->next;
            }
        }
        return dummy->next;
    }
};