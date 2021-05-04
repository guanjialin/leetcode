//
// Created by addzero on 2021/5/4.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> cnt;
        int pow[22] = {0};

        for (auto num : deliciousness) {
            ++cnt[num];
        }

        for (int i = 0; i <= 21; ++i) pow[i] = (1 << i);

        long ans = 0;
        for (auto num : deliciousness) {
            for (int i = 0; i <= 21; ++i) {
                ans +=  (cnt[pow[i] - num] - (num == (pow[i] - num)));
            }
        }

        return (ans / 2) % 1000000007;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> deliciousness = {1048576,1048576};
    cout << Solution().countPairs(deliciousness) << endl;

    return 0;
}

#endif