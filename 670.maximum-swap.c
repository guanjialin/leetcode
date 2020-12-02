//
// Created by addzero on 2020/12/2.
//


#include "header.h"

/*
 * 思路如下：
 * 1. 找到一个递减系列；
 * 2. 找到递减序列右边的最大值（如果有多个，则找最有侧的那个）；
 * 3. 找到递减序列中第一个比右边最大值小的值，进行替换；
 */
int maximumSwap(int num){
    char str_num[10] = {'\0'};
    int size = sprintf(str_num, "%d", num);
    int left = 1, right = size - 1;

    // 得到递减序列
    while (left < size && str_num[left - 1] >= str_num[left]) {
        ++left;
    }

    // 得到递减序列右边的最大值
    int max_val_idx = left - 1;
    for (int i = left; i < size; ++i) {
        if (str_num[i] >= str_num[max_val_idx]) {
            max_val_idx = i;
        }
    }

    // 找最先小于 max_val_idx
    int will_replace = 0;
    for (; will_replace < left && str_num[will_replace] >= str_num[max_val_idx]; ++will_replace);
    if (will_replace < size) {
        char temp = str_num[max_val_idx];
        str_num[max_val_idx] = str_num[will_replace];
        str_num[will_replace] = temp;
    }

    return atoi(str_num);
}

int main() {
    printf("%d\n", maximumSwap(9972));

    return 0;
}