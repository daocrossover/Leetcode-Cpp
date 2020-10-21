// Reservoir Sampling (for follow-up)
// Choose k entries from n numbers. Make sure each number is selected with the probability of k/n
// Basic idea:
// Choose 1, 2, 3, ..., k first and put them into the reservoir.
// For k+1, pick it with a probability of k/(k+1), and randomly replace a number in the reservoir.
// For k+i, pick it with a probability of k/(k+i), and randomly replace a number in the reservoir.
// Repeat until k+i reaches n

// Proof:
// For k+i, the probability that it is selected and will replace a number in the reservoir is k/(k+i)
// For a number in the reservoir before (let's say X), the probability that it keeps staying in the reservoir is
// P(X was in the reservoir last time) × P(X is not replaced by k+i)
// = P(X was in the reservoir last time) × (1 - P(k+i is selected and replaces X))
// = k/(k+i-1) × （1 - k/(k+i) × 1/k）
// = k/(k+i)
// When k+i reaches n, the probability of each number staying in the reservoir is k/n

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
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = head->val, i = 2;
        ListNode* cur = head->next;
        while (cur) {
            int j = rand() % i;
            if (j == 0) res = cur->val;
            i++;
            cur = cur->next;
        }
        return res;
    }
    
private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */