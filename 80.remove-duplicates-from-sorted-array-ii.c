//
// Created by lenovo on 2020/10/25.
//

#include "header.h"

int removeDuplicates(int* nums, int numsSize)
{
    int ans = 1;
    int cnt = 1;

    for (int i = 1; i < numsSize; ++i) {
        cnt = nums[i - 1] == nums[i] ? cnt + 1 : 1;
        if (cnt <= 2) {
            nums[ans++] = nums[i];
        }
    }

    return numsSize ? ans : numsSize;
}

int main()
{
    int data[] = {};
    int ans = removeDuplicates(data, array_int_len(data));
    array_int_print(data, ans);

    return 0;
}