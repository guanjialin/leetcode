//
// Created by addzero on 2020/12/8.
//


#ifdef __LOCAL__

#include "header.h"

#endif

int majorityElement(int* nums, int numsSize){
    int majority = 0, count = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (!count) {
            majority = nums[i];
            count = 1;
        } else {
            count += majority == nums[i] ? 1 : -1;
        }
    }

    return majority;
}

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif