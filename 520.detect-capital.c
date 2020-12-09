//
// Created by addzero on 2020/12/9.
//


#ifdef __LOCAL__

#include "header.h"

#endif

bool detectCapitalUse(char * word)
{
    int size = 0, upper = 0;

    for (char *p = word; *p != '\0'; ++p, ++size) {
        upper += isupper(*p) ? 1 : 0;
    }

    return upper == size || (1 == upper && isupper(*word)) || !upper;
}

#ifdef __LOCAL__

int main() {
    printf("%d\n", detectCapitalUse("USA"));
    printf("%d\n", detectCapitalUse("FlaG"));

    return 0;
}

#endif