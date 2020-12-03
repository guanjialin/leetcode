//
// Created by addzero on 2020/12/3.
//


#ifdef __LOCAL__
#include "header.h"
#endif

bool kLengthApart(int* nums, int numsSize, int k)
{
    int left = -k - 1, right = 0;

    while (right < numsSize) {
        if (nums[right] && (right - left) <= k) {
            return false;
        }
        left = nums[right] ? right : left;
        ++right;
    }

    return true;
}

#ifdef __LOCAL__
int main()
{
    int nums[] = {0,1,0,1};
    printf("%d\n", kLengthApart(nums, array_int_len(nums), 2));
    
    return 0;
}
#endif