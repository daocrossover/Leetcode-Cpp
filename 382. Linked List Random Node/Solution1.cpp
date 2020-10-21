// 382. Linked List Random Node
// Description:
// Given a singly linked list, return a random node's value from the linked list.
// Each node must have the same probability of being chosen.

// Follow up:
// What if the linked list is extremely large and its length is unknown to you? 
// Could you solve this efficiently without using extra space?

// Example:
// Init a singly linked list [1,2,3].
// ListNode head = new ListNode(1);
// head.next = new ListNode(2);
// head.next.next = new ListNode(3);
// Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
// solution.getRandom();

// Calculate the length of the LinkedList
// traverse the list twice, length is known
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <cstdlib>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        len = 0;
        ListNode* cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int n = rand() % len;
        ListNode* cur = head;
        while (n > 0) {
            cur = cur->next;
            n--;
        }
        return cur->val;
    }

private:
    ListNode *head;
    int len;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */