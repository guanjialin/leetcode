//
// Created by dell on 2020/10/26.
//

#include "header.h"

void sortColors(int* nums, int numsSize)
{
    int iter = 0;
    int left = 0, right = numsSize - 1;

    while (iter <= right) {
        if (nums[iter] == 0) {
            array_int_swap(nums, left++, iter++);
        } else if (nums[iter] == 2) {
            array_int_swap(nums, right--, iter);
        } else {
            ++iter;
        }
    }
}

int main()
{
    int data[] = {2,0,2,1,1,0,0,0,0};
    sortColors(data, array_int_len(data));
    array_int_print(data, array_int_len(data));

    return 0;
}