//
// Created by addzero on 2021/1/14.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int cur = 0;
        vector<bool> ans;
        ans.reserve(A.size());

        for (const auto &a : A) {
            cur = (cur * 2 + a) % 5;
            ans.emplace_back(cur == 0);
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> A = {0, 1, 1};
    vector_print(Solution().prefixesDivBy5(A));

    return 0;
}

#endif