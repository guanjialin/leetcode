//
// Created by addzero on 2021/1/8.
//


#ifdef __LOCAL__

#include "header.h"

#endif

#if 0
// 这个方法跟机器位数有关，不通用，补充一个评论区大佬的方法
class Solution {
public:
    int findComplement(int num) {
        num = ~num;
        unsigned int base = 0x80000000;

        while (num & base) {
            num &= ~base;
            base >>= 1;
        }

        return num;
    }
};
#else
class Solution {
public:
    int findComplement(int num) {
        int temp = 1;
        while (temp < num) {
            temp <<= 1;
        }

        return temp - 1 - num;
    }
};
#endif

#ifdef __LOCAL__

int main() {
    cout << Solution().findComplement(5) << endl;

    return 0;
}

#endif