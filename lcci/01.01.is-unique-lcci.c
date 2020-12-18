//
// Created by addzero on 2020/11/25.
//


#include "header.h"

// TODO 本题还可用一个 int 做位运算，不知道算不算额外的数据结构
#ifdef __QSORT__
// 使用排序的解法
static int cmp(const void *x, const void *y)
{
    return *(char *) x - *(char *) y;
}

bool isUnique(char *astr)
{
    int len = strlen(astr);

    qsort(astr, len, sizeof(char), cmp);

    for (int i = 0; i < len - 1; ++i) {
        if (astr[i] == astr[i + 1]) {
            return false;
        }
    }

    return true;
}
#else
// 使用数组计数的解法
bool isUnique(char* astr){
    int count[128] = {0};

    while (*astr != '\0') {
        if (count[*astr]++ >= 1) {
            return false;
        }
        ++astr;
    }
    return true;
}
#endif

int main() {


    return 0;
}