//
// Created by addzero on 2021/1/15.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for (int i = 1; i < 9; ++i) {
            int temp = i;
            int cur = i + 1;

            while (temp <= high) {
                if (temp >= low) {
                    ans.push_back(temp);
                }
                temp = temp * 10 + cur++;
            }
        }
        std::sort(ans.begin(), ans.end());

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector_print(Solution().sequentialDigits(100, 300));

    return 0;
}

#endif