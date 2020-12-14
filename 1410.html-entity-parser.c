//
// Created by addzero on 2020/12/14.
//


#ifdef __LOCAL__

#include "header.h"

#endif

static void symbol_process(char *text, int *left, int *right)
{
    if (!strncmp(text + *right, "&quot;", sizeof(char) * 6)) {
        text[(*left)++] = '"';
        *right += 6;
    } else if (!strncmp(text + *right, "&apos;", sizeof(char) * 6)) {
        text[(*left)++] = '\'';
        *right += 6;
    } else if (!strncmp(text + *right, "&amp;", sizeof(char) * 5)) {
        text[(*left)++] = '&';
        *right += 5;
    } else if (!strncmp(text + *right, "&gt;", sizeof(char) * 4)) {
        text[(*left)++] = '>';
        *right += 4;
    } else if (!strncmp(text + *right, "&lt;", sizeof(char) * 4)) {
        text[(*left)++] = '<';
        *right += 4;
    } else if (!strncmp(text + *right, "&frasl;", sizeof(char) * 7)) {
        text[(*left)++] = '/';
        *right += 7;
    } else {
        text[(*left)++] = text[(*right)++];
    }
}

char * entityParser(char * text){
    int left = 0, right = 0;

    while (text[right] != '\0') {
        if (text[right] == '&') {
            symbol_process(text, &left, &right);
        } else {
            text[left++] = text[right++];
        }
    }
    text[left] = '\0';

    return text;
}

#ifdef __LOCAL__

int main() {
    char text[] = "x &gt; y &amp;&amp; x &lt; y is always false";
    printf("%s\n", entityParser(text));

    return 0;
}

#endif