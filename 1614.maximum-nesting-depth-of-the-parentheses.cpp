//
// Created by lenovo on 2020/10/30.
//


#ifdef __cplusplus
#include "cppheader.h"

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> stk;

        for (auto c : s) {
            if (c == '(') {
                stk.push(c);
                ans = stk.size() > ans ? stk.size() : ans;
            } else if (c == ')') {
                stk.pop();
            }
        }

        return ans;
    }
};
#else
#include "header/header.h"
int maxDepth(char * s)
{
    int ans = 0, balance = 0;

    while (*s != '0') {
        if (*s == '(') {
            ans = ++balance > ans ? balance : ans;
        } else if (*s == ')') {
            --balance;
        }
        ++s;
    }

    return ans;
}
#endif

int main()
{
#ifdef __cplusplus
    cout << Solution().maxDepth("(1+(2*3)+((8)/4))+1") << endl;
#else
    printf("%d\n", maxDepth("(1+(2*3)+((8)/4))+1"));
#endif
}