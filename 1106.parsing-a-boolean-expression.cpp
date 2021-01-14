//
// Created by addzero on 2020/11/4.
//


#include "header/cppheader.h"


class Solution {
public:
    bool parseBoolExpr(string expression) {
        for (auto c : expression) {
            if (c == '!' || c == '&' || c == '|') {
                stk_symbol.push(c);
            } else if (c == 't' || c == 'f' || c== '(') {
                stk_data.push(c);
            } else if (c == ')') {
                char will_insert;
                if (stk_symbol.top() == '|') {
                    will_insert = process_or();
                } else if (stk_symbol.top() == '&') {
                    will_insert = process_and();
                } else if (stk_symbol.top() == '!') {
                    will_insert = process_not();
                }

                stk_symbol.pop();
                while (stk_data.top() != '(') {
                    stk_data.pop();
                }
                stk_data.pop();
                stk_data.push(will_insert);
            }
        }

        return stk_data.top() == 't';
    }

private:
    char process_or() {
        while (stk_data.top() != '(') {
            if (stk_data.top() == 't') {
                return 't';
            }
            stk_data.pop();
        }

        return 'f';
    }

    char process_and() {
        while (stk_data.top() != '(') {
            if (stk_data.top() == 'f') {
                return 'f';
            }
            stk_data.pop();
        }

        return 't';
    }

    char process_not() {
        return stk_data.top() == 'f' ? 't' : 'f';
    }

private:
    stack<char> stk_symbol;
    stack<char> stk_data;
};

int main() {
    cout << Solution().parseBoolExpr("!(f)");   // 1
    cout << Solution().parseBoolExpr("|(f,t)"); // 1
    cout << Solution().parseBoolExpr("&(t,f)"); // 0
    cout << Solution().parseBoolExpr("|(&(t,f,t),!(t))");   // 0

    return 0;
}