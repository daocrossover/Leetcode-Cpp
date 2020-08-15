// Space O(1) (except returned copied list):
// Time Complexity: O(3n) = O(n) (three pass)
// Space Complexity: O(n) = O(n) (only n -> copied list)

// Definition for a Node.

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node *l1, *l2, *dummy;
        // insert each new node after it's corresponding node in the list.
        for (l1 = head; l1 != nullptr; l1 = l1->next->next) {
            l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
        }
        // assign random pointer for new inserted nodes
        for (l1 = head; l1 != nullptr; l1 = l1->next->next) {
            if (l1->random) {
                l1->next->random = l1->random->next;
            }
        }
        // separate the combined list
        dummy = head->next;
        for (l1 = head; l1 != nullptr; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next) {
                l2->next = l2->next->next;
            }
        }
        return dummy;
    }
};