//
// Created by addzero on 2020/12/2.
//


#include "header.h"

char * removeKdigits(char * num, int k){
    int top = 0;
    int iter = 1;
    int len = strlen(num);

    if (0 == len) {
        return "0";
    }

    while (iter < len && k > 0) {
        while (top >= 0 && k > 0 && num[iter] < num[top]) {
            --top;
            --k;
        }
        num[++top] = num[iter++];
    }

    while (iter < len) {
        num[++top] = num[iter++];
    }
    num[top + 1 - k] = '\0';

    while (*num != '\0' && '0' == *num) {
        ++num;
    }

    return '\0' == *num ? "0" : num;
}

int main() {
    char num1[] = "1432219";
    char num2[] = "10200";
    char num3[] = "10";
    printf("%s\n", removeKdigits(num1, 4)); //
    printf("%s\n", removeKdigits(num2, 1)); // 200
    printf("%s\n", removeKdigits(num3, 2)); // 0

    return 0;
}