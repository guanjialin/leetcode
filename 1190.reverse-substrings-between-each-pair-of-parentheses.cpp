//
// Created by addzero on 2021/1/15.
//


#ifdef __LOCAL__

#include "header.h"

#endif

#if 0
// 从内到外，标准的栈思维，时间复杂度O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        queue<char> q;

        for (char &c : s) {
            if (')' == c) {
                while (ans.back() != '(') {
                    q.push(ans.back()); ans.pop_back();
                }
                ans.pop_back();

                while (!q.empty()) {
                    ans.push_back(q.front()); q.pop();
                }
            } else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};
#else
// 评论区大佬的解法，从外到内，O(1)解法
class Solution {
public:
    string reverseParentheses(string s) {
        string ans;
        stack<int> stk;
        unordered_map<int, int> bracket;

        for (int i = 0; i < s.size(); ++i) {
            if ('(' == s[i]) {
                stk.push(i);
            } else if (')' == s[i]) {
                bracket[stk.top()] = i;
                bracket[i] = stk.top();
                stk.pop();
            }
        }

        for (int i = 0, d = 1; i < s.size(); i += d) {
            if ('(' == s[i] || ')' == s[i]) {
                i = bracket[i];
                d *= -1;
            } else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};
#endif

#ifdef __LOCAL__

int main() {
    cout << Solution().reverseParentheses("(ed(et(oc))el)");

    return 0;
}

#endif