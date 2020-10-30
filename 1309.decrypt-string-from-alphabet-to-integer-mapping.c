//
// Created by lenovo on 2020/10/30.
//

#include "header.h"

char * freqAlphabets(char * s)
{
    int len = strlen(s);
    char *ans = (char *) calloc(len, sizeof(char));
    int iter = 0, ans_iter = 0;

    while (iter < len) {
        if (iter < len - 2 && s[iter + 2] == '#') {
            ans[ans_iter++] = (s[iter] - '0') * 10 + s[iter + 1] - '0' - 1 + 'a';
            iter += 3;
        } else {
            ans[ans_iter++] = s[iter++] - 1 - '0' + 'a';
        }
    }

    return ans;
}

int main()
{
    printf("%s\n", freqAlphabets("10#11#12"));   // jkab;

    return 0;
}