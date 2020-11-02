//
// Created by dell on 2020/11/2.
//

#include "header.h"

int isPrefixOfWord(char * sentence, char * searchWord){
    int word = 1;
    char *p;

    while (*sentence != '\0') {
        p = searchWord;

        while (*p != '\0' && *p == *sentence && *sentence != ' ') {
            ++p;
            ++sentence;
        }

        if (*p == '\0') {
            return word;
        }

        while (*sentence != '\0' && *(sentence++) != ' ');
        ++word;
    }

    return -1;
}

int main()
{
    printf("%d\n", isPrefixOfWord("i love eating burger", "burg"));
    printf("%d\n", isPrefixOfWord("i love eating burger", "at"));

    return 0;
}