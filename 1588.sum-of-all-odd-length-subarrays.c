//
// Created by addzero on 2020/12/2.
//


#include "header.h"

#if 0
// O(N2)
int sumOddLengthSubarrays(int* arr, int arrSize){
    // 先求前缀和
    for (int i = 1; i < arrSize; ++i) {
        arr[i] += arr[i - 1];
    }

    int ans = 0;
    for (int i = 0; i < arrSize; ++i) {
        int len = i;
        while (len < arrSize) {
            ans += i == 0 ? arr[len] : (arr[len] - arr[i - 1]);
            len += 2;
        }
    }

    return ans;
}
#else
// 大佬的 O(N) 解法
int sumOddLengthSubarrays(int* arr, int arrSize){
    int ans = 0;

    for (int i = 0; i < arrSize; ++i) {
        int left_odd = (i + 1) / 2, left_even = i / 2 + 1;
        int right_odd = (arrSize - i) / 2, right_even = (arrSize - 1 - i) / 2 + 1;
        ans += arr[i] * (left_even * right_even + left_odd * right_odd);
    }

    return ans;
}
#endif

int main() {
    int data[] = {1, 4, 2, 5, 3};
    printf("%d\n", sumOddLengthSubarrays(data, array_int_len(data)));

    return 0;
}