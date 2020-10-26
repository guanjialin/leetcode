//
// Created by dell on 2020/10/26.
//

#include "header.h"

void sortColors(int* nums, int numsSize)
{
    int left_slow = 0, left_fast = 0;
    int right_slow = numsSize - 1, right_fast = numsSize - 1;

    while (left_fast <= right_fast) {
        if (nums[left_fast] == 0) {
            nums[left_fast++] = 1;
            nums[left_slow++] = 0;
        } else if (nums[left_fast] == 2) {

        }
    }
}

int main()
{
    int data[] = {2, 0, 2, 1, 1, 0};
    sortColors(data, array_int_len(data));
    array_int_print(data, array_int_len(data));

    return 0;
}