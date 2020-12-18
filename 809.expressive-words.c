//
// Created by addzero on 2020/12/18.
//


#ifdef __LOCAL__
#include "header.h"
#endif

// TODO 可以先预算计算好 S 的结构，直接跟 word比较，速度应该快不少
static bool expressive(const char *s, int slen, const char *word, int wlen) {
    while (wlen >= 0 && slen >= 0) {
        int srep = 1, wrep = 1;

        while (slen >= 1 && s[slen - 1] == s[slen]) {
            --slen;
            ++srep;
        }

        while (wlen >= 1 && word[wlen - 1] == word[wlen]) {
            --wlen;
            ++wrep;
        }

        if (s[slen] != word[wlen] || wrep > srep || (wrep != srep && srep < 3)) {
            return false;
        }

        --wlen; --slen;
    }

    return wlen < 0 && slen < 0;
}

int expressiveWords(char * S, char ** words, int wordsSize){
    int ans = 0;
    int len = strlen(S) - 1;

    for (int i = 0; i < wordsSize; ++i) {
        ans += expressive(S, len, words[i], strlen(words[i]) - 1);
    }

    return ans;
}

#ifdef __LOCAL__
int main()
{
    char **words = (char **) calloc(3, sizeof(char *));
    words[0] = "ahello"; words[1] = "hi"; words[2] = "helo";
    printf("%d\n", expressiveWords("", words, 3));
    
    return 0;
}
#endif