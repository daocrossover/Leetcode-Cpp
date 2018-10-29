// description:
// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?


// Two Pointers Solution:

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (!fast || !fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};