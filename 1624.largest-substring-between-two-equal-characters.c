//
// Created by dell on 2020/11/2.
//

#include "header.h"

int maxLengthBetweenEqualCharacters(char * s){
    int ans = -1;
    int record[26];
    memset(record, -1, sizeof(int) * 26);

    for (int i = 0; s[i] != '\0'; ++i) {
        if (record[s[i] - 'a'] == -1) {
            record[s[i] - 'a'] = i;
        } else {
            int  dist = i - record[s[i] - 'a'] - 1;
            ans = dist > ans ? dist : ans;
        }
    }

    return ans;
}

int main()
{
    printf("%d\n", maxLengthBetweenEqualCharacters("cbzxy"));

    return 0;
}