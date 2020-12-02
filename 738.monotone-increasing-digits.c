//
// Created by addzero on 2020/12/2.
//


#include "header.h"

int monotoneIncreasingDigits(int N){
    int stk[10] = {0};
    int top = -1;

    while (N != 0) {
        int cur = N % 10;
        if (top != -1 && cur > stk[top]) {
            for (int i = top; i >= 0 && stk[i] != 9; --i) {
                stk[i] = 9;
            }
            --cur;
        }
        stk[++top] = cur;

        N /= 10;
    }

    for (int i = top; i >= 0; --i) {
        N = N * 10 + stk[i];
    }

    return N;
}

int main() {
    printf("%d\n", monotoneIncreasingDigits(4321));
    printf("%d\n", monotoneIncreasingDigits(11762));
    printf("%d\n", monotoneIncreasingDigits(11769));
    printf("%d\n", monotoneIncreasingDigits(1234));
    printf("%d\n", monotoneIncreasingDigits(4381));

    return 0;
}