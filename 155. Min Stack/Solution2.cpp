// One stack solution

#include <stack>
#include <climits>
using std::stack;

class MinStack {
private:
    stack<int> data_stack;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        // only push the old minimum value when the current 
        // minimum value changes after pushing the new value x
        if (x <= min) {
            data_stack.push(min);
            min = x;
        }
        data_stack.push(x);
    }
    
    void pop() {
        if (data_stack.top() == min) {
            data_stack.pop();
            min = data_stack.top();
        }
        data_stack.pop();
    }
    
    int top() {
        return data_stack.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */