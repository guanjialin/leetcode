//
// Created by addzero on 2021/1/15.
//


#ifdef __LOCAL__
#include "header.h"
#endif

class Solution {
public:
    int countLargestGroup(int n) {
        int eq = 0, max_v = 0;
        unordered_map<int, int> acc;

        for (int i = 1; i <= n; ++i) {
            ++acc[cal(i)];
            if (acc[cal(i)] > max_v) {
                max_v = acc[cal(i)];
                eq = 1;
            } else if (acc[cal(i)] == max_v) {
                ++eq;
            }
        }

        return eq;
    }

private:
    static inline int cal(int n) {
        int ans = 0;

        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }
};

#ifdef __LOCAL__
int main()
{
    cout << Solution().countLargestGroup(2) << endl;

    return 0;
}
#endif