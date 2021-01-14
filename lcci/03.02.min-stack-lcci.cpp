//
// Created by addzero on 2021/1/14.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk_data.push(x);

        if (stk_min.empty() || x <= stk_min.top()) {
            stk_min.push(x);
        }
    }

    void pop() {
        if (stk_data.top() == stk_min.top()) {
            stk_min.pop();
        }
        stk_data.pop();
    }

    int top() {
        return stk_data.top();
    }

    int getMin() {
        return stk_min.top();
    }

private:
    stack<int> stk_data;
    stack<int> stk_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#ifdef __LOCAL__

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();   //--> 返回 -3.
    minStack.pop();
    minStack.top();      //--> 返回 0.
    minStack.getMin();   //--> 返回 -2.

    return 0;
}

#endif