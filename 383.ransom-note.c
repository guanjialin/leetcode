//
// Created by addzero on 2020/11/4.
//


#include "header.h"

bool canConstruct(char * ransomNote, char * magazine){
    int record[26] = {0};

    while (*magazine != '\0') {
        ++record[*magazine++ - 'a'];
    }

    while (*ransomNote != '\0') {
        if (--record[*ransomNote++ - 'a'] < 0) {
            return  false;
        }
    }

    return true;
}

int main() {
    printf("%d\n", canConstruct("a", "b"));

    return 0;
}