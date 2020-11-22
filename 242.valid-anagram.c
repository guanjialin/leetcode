//
// Created by addzero on 2020/11/22.
//


#include "header.h"

bool isAnagram(char * s, char * t)
{
    int count[26] = {0};

    while (*s != '\0' && *t != '\0') {
        ++count[*s - 'a'];
        --count[*t - 'a'];
        ++s;
        ++t;
    }

    if (*s != '\0' || *t != '\0') {
        return false;
    }

    for (int i = 0; i < 26; ++i) {
        if (count[i] != 0) {
            return  false;
        }
    }

    return true;
}

int main()
{
    printf("%d\n", isAnagram("anagram", "nagaram"));
    printf("%d\n", isAnagram("rat", "car"));

    return 0;
}