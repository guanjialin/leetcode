//
// Created by addzero on 2020/12/4.
//


#ifdef __LOCAL__
#include <utility>

#include "cppheader.h"
#endif

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        for (int i = 0; i < combinationLength; ++i) {
            stk.push(i);
            s.push_back(characters[i]);
        }

        this->characters = std::move(characters);
        this->combination_length = combinationLength;
    }

    string next() {
        string ans = s;
        stk.top() += 1;
        s.back() = stk.top() < characters.size() ? characters[stk.top()] : s.back();

        // 如果最后的值不符合预期，则进行出栈
        while (!stk.empty() && stk.top() + (combination_length - stk.size()) >= characters.size()) {
            stk.pop();
            if (!stk.empty()) {
                stk.top() += 1;
                s[stk.size() - 1] = characters[stk.top()];
            }
        }

        // 回填
        while (!stk.empty() && stk.size() != combination_length && stk.top() != characters.size() - 1) {
            stk.push(stk.top() + 1);
            s[stk.size() - 1] = characters[stk.top()];
        }

        return ans;
    }

    bool hasNext() {
        return stk.size() == combination_length;
    }

private:
    string characters;
    int combination_length;
    stack<int> stk; // 存储目前的索引
    string s;       // 目前的值
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

#ifdef __LOCAL__
int main()
{
    CombinationIterator obj("abcd", 2);
    while (obj.hasNext()) {
        cout << obj.next() << endl;
    }
    
    return 0;
}
#endif