// Recursive Solution:

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        return flatten(head, nullptr);
    }
    
private:
    Node* flatten(Node* head, Node* tail) {
        if (head == nullptr) return tail;
        head->next = flatten(head->child, flatten(head->next, tail));
        if (head->next != nullptr) head->next->prev = head;
        head->child = nullptr;
        return head;
    }
};