//
// Created by addzero on 2020/12/15.
//


#ifdef __LOCAL__

#include "header.h"

#endif

// TODO 是否有空间复杂度O(1)的解法?
int getMaximumGenerated(int n)
{
    int max = 0;
    int arr[n + 1];
    arr[0] = 0; arr[1] = 1;

    for (int i = 2; i <= n; ++i) {
        arr[i] = i % 2 ? arr[i / 2] + arr[i / 2 + 1] : arr[i / 2];
        max = fmax(max, arr[i]);
    }

    return n <= 1 ? n : max;
}

#ifdef __LOCAL__

int main() {
    printf("%d\n", getMaximumGenerated(100));

    return 0;
}

#endif