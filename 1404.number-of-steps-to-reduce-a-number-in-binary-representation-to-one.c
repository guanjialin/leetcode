//
// Created by addzero on 2020/12/9.
//


#ifdef __LOCAL__

#include "header.h"

#endif

int numSteps(char * s){
    int ans = 0;
    int right = strlen(s) - 1;

    while (right > 0) {
        if (s[right] == '1') {
            int step = 0;
            while (right >= 0 && '1' == s[right]) {
                --right;
                ++step;
            }
            if (right >= 0) {
                s[right] = '1';
            }
            ans += step + 1;
        } else {
            --right;
            ++ans;
        }
    }

    return ans;
}

#ifdef __LOCAL__

int main() {
    char data1[] = "111";
    printf("%d\n", numSteps(data1));

    char data2[] = "11001";
    printf("%d\n", numSteps(data2));

    char data3[] = "10";
    printf("%d\n", numSteps(data3));

    char data4[] = "1";
    printf("%d\n", numSteps(data4));

    return 0;
}

#endif