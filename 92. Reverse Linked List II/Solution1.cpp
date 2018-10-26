// Description:
// Reverse a linked list from position m to n. Do it in one-pass.

// Note: 1 ≤ m ≤ n ≤ length of list.

// Example:
// Input: 1->2->3->4->5->NULL, m = 2, n = 4
// Output: 1->4->3->2->5->NULL


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        // find the pre node
        for (int i = 0; i < m - 1; ++i) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        for (int i = 0; i < n - m; ++i) {
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy->next;
    }
};