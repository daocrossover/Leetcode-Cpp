// Description:
// Given a linked list, return the node where the cycle begins.
// If there is no cycle, return null.

// Note: Do not modify the linked list.

// Follow up:
// Can you solve it without using extra space?


// Solution:
// using two pointers, one of them one step at a time. another pointer each take two steps
// Suppose the first meet at step k, the length of the Cycle is r. so..2k-k=nr,k=nr
// the distance between the start node of list and the start node of cycle is s.
// the distance between the start of list and the first meeting node is k
// (the pointer which wake one step at a time waked k steps)
// the distance between the start node of cycle and the first meeting node is m,
// so...s=k-m, s=nr-m=(n-1)r+(r-m),here we takes n = 1
// so, using one pointer start from the start node of list,
// another pointer start from the first meeting node,
// all of them wake one step at a time, the first time they meeting each other is the start of the cycle.

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head, *entry = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }
                return entry;				
            }
        }			
        return nullptr;
    }
};