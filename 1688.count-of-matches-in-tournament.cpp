//
// Created by addzero on 2021/1/13.
//


#ifdef __LOCAL__

#include "header.h"

#endif

#if 0
class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;

        while (n != 1) {
            ans += n / 2;
            n = n % 2 + n / 2;
        }

        return ans;
    }
};
#else
// 还是评论区大佬秀
class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};
#endif

#ifdef __LOCAL__

int main() {
    cout << Solution().numberOfMatches(7) << endl;

    return 0;
}

#endif