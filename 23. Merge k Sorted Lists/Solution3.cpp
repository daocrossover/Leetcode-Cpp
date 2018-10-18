// Merge lists one by one:
// Time Complexity: O(Nk)
// Space Complexity: O(1)

#include<vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];
        ListNode *head = mergeTwoLists(lists[0], lists[1]);
        for (int i = 2; i < lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return dummy->next;
    }
};