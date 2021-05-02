//
// Created by addzero on 2021/5/2.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size());
        if (!k) return ans;
        int sum = k > 0 ? std::accumulate(code.begin() + 1, code.begin() + k + 1, 0)
                        : std::accumulate(code.rbegin(), code.rbegin() - k, 0);
        int direction = k > 0 ? 1 : -1;

        for (int i = 0; i < code.size(); ++i) {
            ans[i] = sum;
            int val1 = direction * code[i + (k > 0)];
            int val2 = direction * code[(i + k + code.size() + (k > 0)) % code.size()];
            sum = sum - val1 + val2;
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> code1 = {2,4,9,3};
    vector_print(Solution().decrypt(code1, -2));

    vector<int> code2 = {5,7,1,4};
    vector_print(Solution().decrypt(code2, 3));

    return 0;
}

#endif