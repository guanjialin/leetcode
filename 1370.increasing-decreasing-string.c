//
// Created by lenovo on 2020/10/30.
//

#include "header.h"

char * sortString(char * s)
{
    int len = strlen(s);
    char *ans = (char *) calloc(len + 1, sizeof(char ));
    int ans_iter = 0;
    int cal[26] = {0};

    for (int i = 0; i < len; ++i) {
        ++cal[s[i] - 'a'];
    }

    while (ans_iter != len) {
        for (int i = 0; i < 26 && ans_iter != len; ++i) {
            if (cal[i] > 0) {
                ans[ans_iter++] = i + 'a';
                --cal[i];
            }
        }

        for (int i = 25; i >= 0 && ans_iter != len; --i) {
            if (cal[i] > 0) {
                ans[ans_iter++] = i + 'a';
                --cal[i];
            }
        }
    }

    return ans;
}

int main()
{
    printf("%s\n", sortString("aaaabbbbcccc"));

    return 0;
}