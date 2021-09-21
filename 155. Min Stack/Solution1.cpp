// 155. Min Stack
// Description:
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:
// MinStack() initializes the stack object.
// void push(val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.

// Example 1:
// Input:
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output:
// [null,null,null,null,-3,null,0,-2]

// Explanation:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
 
// Constraints:
// 1. -2^31 <= val <= 2^31 - 1
// 2. Methods pop, top and getMin operations will always be called on non-empty stacks.
// 3. At most 3 * 10^4 calls will be made to push, pop, top, and getMin.

// Two stacks solution:
// Maintain a min stack which top stores the current min in the stack

#include <stack>
using std::stack;

class MinStack {
private:
    stack<int> data_stack;
    stack<int> min_stack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data_stack.push(x);
        if (min_stack.empty() || x <= min_stack.top()) {
            min_stack.push(x);
        }
    }
    
    void pop() {
        if (min_stack.top() == data_stack.top()) {
            min_stack.pop();
        }
        data_stack.pop();
    }
    
    int top() {
        return data_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
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