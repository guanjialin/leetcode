//
// Created by dell on 2020/10/30.
//

#include "header/cppheader.h"


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0, slow = 0, fast = 0;

        while (fast < s.size()) {
            if (s[fast] == '(') {
                ++count;
            } else if (s[fast] == ')') {
                if (count > 0) {
                    --count;
                } else {
                    ++fast;
                    continue;
                }
            }
            s[slow++] = s[fast++];
        }
        int end = slow;

        while (count > 0) {
            count += s[--slow] == '(' ? -1 : 0;
        }

        slow = slow;
        fast = slow;
        while (fast < end) {
            if (s[fast] == '(') {
                ++fast;
            } else {
                s[slow++] = s[fast++];
            }
        }
        s[slow] = '\0';
        s.resize(slow);

        return s;
    }
};


int main()
{
    cout << Solution().minRemoveToMakeValid("(a(b(c)d)");

    return 0;
}