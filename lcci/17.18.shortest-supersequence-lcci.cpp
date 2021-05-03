//
// Created by addzero on 2021/5/3.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        unordered_set<int> set_small(small.begin(), small.end());
        unordered_map<int, int> set_big;
        int left = 0, right = 0;
        int min_len = INT_MAX;
        vector<int> ans(2);

        do {
            if (set_small.count(big[right])) ++set_big[big[right]];
            while (set_big.size() == set_small.size()) {
                while (!set_small.count(big[left])) ++left;

                if (right - left < min_len) {
                    ans[0] = left;
                    ans[1] = right;
                    min_len = right - left;
                }

                if (--set_big[big[left]] == 0) set_big.erase(big[left]);
                ++left;
            }

            ++right;
        } while (right < big.size());

        return ans[1] ? ans : vector<int>();
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> big = {7,5,9,0,2,1,3,5,7,9,1,1,5,8,8,9,7}, small = {1,5,9};
    vector_print(Solution().shortestSeq(big, small));

    return 0;
}

#endif