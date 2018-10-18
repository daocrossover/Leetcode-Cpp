// Recursive Solution:

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *l = head;
        if (head && head->next) {
            l = head->next;
            head->next = swapPairs(l->next);
            l->next = head;
        }
        return l;
    }
};