// Description:
// Merge k sorted linked lists and return it as one sorted list.
// Analyze and describe its complexity.

// Example:
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6


// MinHeap Solution:
// Time Complexity: O(Nlogk)
// 1. There are N nodes in the final linked list.
// 2. O(logk) for every pop and insertion to priority queue.
// 3. But finding the node with the smallest value just costs O(1) time.
// Space Complexity:
// 1. O(n) creating a new linked list costs O(n) space.
// 2. O(k) the priority queue (often implemented with heaps) costs O(k) space

#include<vector>
#include<queue>
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
        // construct compare function for data structure ListNode*
        struct cmp{
            bool operator() (ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };
        ListNode *head = new ListNode(-1);
        ListNode *p = head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) heap.push(lists[i]);
        }
        while (!heap.empty()) {
            ListNode* t = heap.top();
            heap.pop();
            p->next = t;
            p = p->next;
            if (t->next) heap.push(t->next);
        }
        return head->next;
    }
};