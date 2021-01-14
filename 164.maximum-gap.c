//
// Created by addzero on 2020/11/26.
//


#include "header.h"

#ifdef __QSORT__
static int cmp(const void *x, const void *y) {
    return *(int *) x - *(int *) y;
}

int maximumGap(int* nums, int numsSize){
    if (numsSize < 2) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = nums[1] - nums[0];
    for (int i = 2; i < numsSize; ++i) {
        ans = fmax(nums[i] - nums[i - 1], ans);
    }

    return ans;
}
#else
int maximumGap(int* nums, int numsSize)
{

}
#endif

int main() {
    int data[] = {3, 6, 9, 1};
    printf("%d\n", maximumGap(data, array_int_len(data)));

    return 0;
}