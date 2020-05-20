// One stack solution

#include<stack>
#include<climits>
using std::stack;

class MinStack {
private:
    stack<int> dataStack;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        if (x <= min) {
            dataStack.push(min);
            min = x;
        }
        dataStack.push(x);
    }
    
    void pop() {
        if (dataStack.top() == min) {
            dataStack.pop();
            min = dataStack.top();
        }
        dataStack.pop();
    }
    
    int top() {
        return dataStack.top();
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