//
// Created by addzero on 2021/1/6.
//


#ifdef __LOCAL__

#include "header.h"

#endif

bool oneEditAway(char* first, char* second){
    int before = 0;
    int len_first = strlen(first) - 1, len_second = strlen(second) - 1;

    while (before <= len_first && before <= len_second && first[before] == second[before]) ++before;
    while (len_first >= 0 && len_second >= 0 && first[len_first] == second[len_second]) {--len_first; --len_second;}

    if ((len_first == -1 && len_second == -1) ||(before == len_first && before == len_second)
        || (before == len_first && before == len_second + 1)
        || (before == len_second && before == len_first + 1)) {
        return true;
    }

    return false;
}

#ifdef __LOCAL__

int main() {
    printf("%d\n", oneEditAway("pale", "ple"));
    printf("%d\n", oneEditAway("ple", "pale"));
    printf("%d\n", oneEditAway("ple", "pke"));
    printf("%d\n", oneEditAway("pales", "pal"));
    printf("%d\n", oneEditAway("horse", "orse"));
    printf("%d\n", oneEditAway("hors", "horse"));
    printf("%d\n", oneEditAway("horse", "jorse"));
    printf("%d\n", oneEditAway("horse", "horss"));
    printf("%d\n", oneEditAway("", ""));
    printf("%d\n", oneEditAway("", "a"));

    return 0;
}

#endif