//
// Created by addzero on 2020/11/25.
//


#include "header.h"

// 自己写的太丑了，抄一抄评论的代码
// 根据定义，任何丑数都可以写成 2^x + 3^y + 3^z
bool isUgly(int num)
{
    if (num <= 0) {
        return false;
    }

    while (0 == num % 2) num /= 2;
    while (0 == num % 3) num /= 3;
    while (0 == num % 5) num /= 5;

    return 1 == num;
}

int main() {
    printf("%d\n", isUgly(0));
    printf("%d\n", isUgly(1));
    printf("%d\n", isUgly(2));
    printf("%d\n", isUgly(3));
    printf("%d\n", isUgly(4));
    printf("%d\n", isUgly(5));
    printf("%d\n", isUgly(6));
    printf("%d\n", isUgly(7));

    return 0;
}