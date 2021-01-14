//
// Created by addzero on 2021/1/5.
//


#ifdef __LOCAL__

#include "header.h"

#endif


class FreqStack {
public:
    FreqStack() {
    }

    void push(int x) {
        ++freq_tables[x];
        keys[freq_tables[x]].push_back(x);
        freq_max = freq_tables[x] > freq_max ? freq_tables[x] : freq_max;
    }

    int pop() {
        auto ans = keys[freq_max].back();
        keys[freq_max].pop_back();
        if (keys[freq_max].empty()) {
            keys.erase(freq_max);
            --freq_max;
        }
        --freq_tables[ans];

        return ans;
    }

private:
    int freq_max = 0;
    unordered_map<int, int> freq_tables;
    unordered_map<int, vector<int>> keys;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

#ifdef __LOCAL__

int main() {
    FreqStack stk;
    stk.push(5);
    stk.push(7);
    stk.push(5);
    stk.push(7);
    stk.push(4);
    stk.push(5);
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;
    cout << stk.pop() << endl;

    return 0;
}

#endif