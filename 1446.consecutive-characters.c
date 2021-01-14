//
// Created by addzero on 2020/11/4.
//


#include "header.h"

int maxPower(char * s) {
    int cur = 1;
    int ans = 1;

    for (int i = 1; s[i] != '\0'; ++i) {
        if (s[i] == s[i - 1]) {
            ++cur;
        } else {
            ans = fmax(cur, ans);
            cur = 1;
        }
    }

    return fmax(cur, ans);
}

int main() {
    printf("%d\n", maxPower("leetcode"));

    return 0;
}