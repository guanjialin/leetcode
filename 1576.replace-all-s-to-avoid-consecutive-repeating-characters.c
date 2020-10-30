//
// Created by dell on 2020/10/30.
//

#include "header.h"

char * modifyString(char * s)
{
    int len = strlen(s);
    char prev, next;

    for (int i = 0; i < len; ++i) {
        if (s[i] == '?') {
            prev = i > 0 ? s[i - 1] - 'a' : '?';
            next = i < len - 1 ? s[i + 1] - 'a' : '?';

            for (int j = 0; j < 26; ++j) {
                if (j != prev && j != next) {
                    s[i] = j + 'a';
                    break;
                }
            }
        }
    }

    return s;
}

int main()
{
    char data[] = "??yw?ipkj?";
    printf("%s\n", modifyString(data));

    return 0;
}