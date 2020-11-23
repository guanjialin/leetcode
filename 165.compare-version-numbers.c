//
// Created by addzero on 2020/11/23.
//


#include "header.h"

static int next(char **str)
{
    int ans = 0;
    char *p = *str;

    while (*p != '\0' && *p != '.') {
        ans = ans * 10 + (*p - '0');
        ++p;
    }
    *str = *p == '\0' ? p : p + 1;

    return ans;
}

int compareVersion(char * version1, char * version2){
    while (*version1 != '\0' || *version2 != '\0') {
        int v1 = next(&version1);
        int v2 = next(&version2);

        if (v1 > v2) {
            return 1;
        } else if (v1 < v2) {
            return -1;
        }
    }

    return 0;
}

int main() {
    printf("%d\n", compareVersion("1.01", "1.001"));    // 0
    printf("%d\n", compareVersion("1.0", "1.0.0"));     // 0
    printf("%d\n", compareVersion("0.1", "1.1"));       // -1
    printf("%d\n", compareVersion("1.0.1", "1"));       // 1
    printf("%d\n", compareVersion("7.5.2.4", "7.5.3")); // -1

    return 0;
}