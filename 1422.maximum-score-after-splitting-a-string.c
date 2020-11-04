//
// Created by addzero on 2020/11/4.
//


#include "header.h"

int maxScore(char * s){
    int left = 0, right = 0;
    int ans = 0;

    int len = 0;
    for (; s[len] != '\0'; ++len) {
        right += s[len] == '1' ? 1 : 0;
    }

    for (int i = 0; i < len - 1; ++i) {
        s[i] == '0' ? ++left : --right;
        ans = fmax(ans, left + right);
    }

    return ans;
}

int main()
{
    printf("%d\n", maxScore("011101"));

    return 0;
}