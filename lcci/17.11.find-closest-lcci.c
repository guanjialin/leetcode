//
// Created by dell on 2020/10/26.
//
#include "../header.h"

int findClosest(char** words, int wordsSize, char* word1, char* word2)
{
    int ans = wordsSize;
    int w1 = -1, w2 = -1, index = 0;

    while (index < wordsSize) {
        if (!strcmp(words[index], word1)) {
            w1 = index;
        } else if (!strcmp(words[index], word2)) {
            w2 = index;
        }

        if (w1 != -1 && w2 != -1 && ans > abs(w1 - w2)) {
            ans = abs(w1 - w2);
        }

        ++index;
    }

    return ans;
}

int main()
{
    char *words[10] = {"I","am","a","student","from","a","university","in","a","city"};
    printf("%d\n", findClosest(words, array_len(words, char *), "a", "student"));

    return 0;
}