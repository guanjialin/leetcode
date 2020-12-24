//
// Created by addzero on 2020/12/24.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class StackOfPlates {
public:
    StackOfPlates(int cap) {
        capacity = cap;
    }

    void push(int val) {
        if (!capacity) {
            return;
        }

        if (stk.empty() || stk.back().size() == capacity) {
            stk.emplace_back();
        }
        stk.back().push(val);
    }

    int pop() {
        if (stk.empty()) {
            return -1;
        }

        int ans = stk.back().top();
        stk.back().pop();
        if (stk.back().empty()) {
            stk.pop_back();
        }

        return ans;
    }

    int popAt(int index) {
        if (stk.size() <= index) {
            return  -1;
        }

        int ans = stk.at(index).top();
        stk.at(index).pop();
        if (stk.at(index).empty()) {
            stk.erase(stk.begin() + index);
        }
        return ans;
    }

private:
    int capacity;
    vector<stack<int>> stk;
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */

#ifdef __LOCAL__

int main() {
    auto *obj = new StackOfPlates(2);
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    cout << obj->popAt(0) << endl;
    cout << obj->popAt(0) << endl;
    obj->push(5);
    cout << obj->pop() << endl;
    cout << obj->popAt(0) << endl;

    return 0;
}

#endif