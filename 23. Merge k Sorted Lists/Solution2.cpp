// Divide And Conquer Solution:
// Pair up k lists and merge each pair.
// After the first pairing, k lists are merged into k/2 lists with average 2N/k length,
// then k/4, k/8 and so on.
// Repeat this procedure until we get the final sorted linked list.
// Time Complexity: O(Nlogk)
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
        int interval = 1;
        while (interval < lists.size()) {
            for (int i = 0; i + interval < lists.size(); i += interval*2) {
                lists[i] = mergeTwoLists(lists[i], lists[i+interval]);            
            }
            interval *= 2;
        }
        return lists[0];
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