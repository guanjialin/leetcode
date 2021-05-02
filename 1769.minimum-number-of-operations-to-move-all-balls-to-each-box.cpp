//
// Created by addzero on 2021/5/2.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int lzero = 0, rzero = 0, lcnt = 0, rcnt = 0;
        vector<int> ans(boxes.size());

        for (int i = 0; i < boxes.size(); ++i) {
            rzero += boxes[i] == '1';
            rcnt += boxes[i] == '1' ? i : 0;
        }

        for (int i = 0; i < boxes.size(); ++i) {
            ans[i] = rcnt + lcnt;

            if (boxes[i] == '1') {
                ++lzero;
                --rzero;
            }
            lcnt += lzero;
            rcnt -= rzero;
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector_print(Solution().minOperations("110"));
    vector_print(Solution().minOperations("001011"));

    return 0;
}

#endif