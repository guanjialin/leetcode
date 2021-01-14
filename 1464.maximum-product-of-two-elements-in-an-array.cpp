//
// Created by addzero on 2021/1/8.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = INT_MIN, second = INT_MIN;

        for (auto num : nums) {
            if (num >= first) {
                second = first;
                first = num;
            } else if (num > second) {
                second = num;
            }
        }

        return (first - 1) * (second - 1);
    }
};

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif