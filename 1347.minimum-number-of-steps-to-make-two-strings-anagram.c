//
// Created by dell on 2020/10/30.
//

#include "header.h"

int minSteps(char * s, char * t)
{
    int alpas[26] = {0};
    int alpat[26] = {0};
    int lens = strlen(s);
    int lent = strlen(t);
    int ans = 0;

    for (int i = 0; i < lens; ++i) {
        ++alpas[s[i] - 'a'];
        ++alpat[t[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        if (alpas[i] > alpat[i]) {
            ans += (alpas[i] - alpat[i]);
        }
    }

    return ans;
}

int main()
{
    printf("%d\n", minSteps("bab", "aba"));

    return 0;
}