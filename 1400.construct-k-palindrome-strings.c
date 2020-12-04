//
// Created by addzero on 2020/12/4.
//


#ifdef __LOCAL__
#include "header.h"
#endif

bool canConstruct(char * s, int k)
{
    if (strlen(s) < k) {
        return false;
    }
    int count[26] = {0};

    while (*s != '\0') {
        ++count[*s - 'a'];
        ++s;
    }

    int odd = 0;
    for (int i = 0; i < 26; ++i) {
        if ((odd += count[i] % 2) > k) {
            return false;
        }
    }

    return true;
}

#ifdef __LOCAL__
int main()
{
    printf("%d\n", canConstruct("annabele", 2));
    printf("%d\n", canConstruct("leetcode", 3));
    printf("%d\n", canConstruct("true", 4));
    printf("%d\n", canConstruct("yzyzyzyzyzyzyzy", 2));
    printf("%d\n", canConstruct("cr", 7));

    return 0;
}
#endif