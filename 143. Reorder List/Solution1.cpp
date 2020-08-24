// Description:
// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example 1:
// Given 1->2->3->4, reorder it to 1->4->2->3.

// Example 2:
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        // cut the list to two halves (two pointers)
        // prev will be tail of 1st half
        // slow will be the head of 2nd half
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode *l1 = head, *l2 = reverse(slow); // reverse the 2nd half
        merge(l1, l2); // merge the two halves
    }

private:
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *cur = head, *next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    void merge(ListNode* head1, ListNode* head2) {
        while (head2) {
            ListNode* next = head1->next;
            head1->next = head2;
            head1 = head2;
            head2 = next;
        }
    }
};