//
// Created by addzero on 2021/1/14.
//


#ifdef __LOCAL__
#include "header.h"
#endif

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int *ans = (int *) calloc(rowIndex + 1, sizeof(int));
    *returnSize = rowIndex + 1;
    ans[0] = 1;

    for (int i = 1; i <= rowIndex; ++i) {
        int temp;
        int prev = ans[0];
        for (int j = 1; j < i; ++j) {
            temp = ans[j];
            ans[j] += prev;
            prev = temp;
        }
        ans[i] = 1;
    }

    return ans;
}

#ifdef __LOCAL__
int main()
{
    int size;
    int *ans = getRow(3, &size);
    array_int_print(ans, size);
    
    return 0;
}
#endif