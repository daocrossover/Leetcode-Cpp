// Implement stack using LinkedList with min value

#include <algorithm>

class Node {
public:
    int x;
    int min;
    Node* next;
    
    Node(int x, int min, Node* node) {
        this->x = x;
        this->min = min;
        this->next = node;
    }
};

class MinStack {
private:
    Node* head;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if (head == nullptr) {
            head = new Node(val, val, nullptr);
        } else {
            head = new Node(val, std::min(val, head->min), head);
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->x;
    }
    
    int getMin() {
        return head->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */