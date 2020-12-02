//
// Created by addzero on 2020/12/2.
//


#include "../header.h"

int maxSubArray(int* nums, int numsSize)
{
    int ans = nums[0];

    for (int i = 1; i < numsSize; ++i) {
        nums[i] += fmax(nums[i - 1], 0);
        ans = fmax(ans, nums[i]);
    }

    return ans;
}

int main() {


    return 0;
}