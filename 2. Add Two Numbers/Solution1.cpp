// Description:
// You are given two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.
// Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example:
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.

// Regular Math Solution:

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        while (l1 || l2) {
            int x1 = l1 ? l1->val : 0;
            int x2 = l2 ? l2->val : 0;
            sum = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            ListNode* node = new ListNode(sum);
            p->next = node;
            p = p->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            p->next = node;
        }
        return head->next;
    }
};