//
// Created by lenovo on 2020/10/30.
//

#include "header.h"


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static int f(char *s)
{
    int temp[26] = {0};
    char prev = 'z';
    int ans = 0;

    while (*s != '\0') {
        ++temp[*s - 'a'];
        if (*s <= prev) {
            prev = *s;
            ans = temp[*s - 'a'];
        }
        ++s;
    }

    return ans;
}

int* numSmallerByFrequency(char ** queries, int queriesSize, char ** words, int wordsSize, int* returnSize)
{
    int prefix_sum[12] = {0};

    for (int i = 0; i < wordsSize; ++i) {
        ++prefix_sum[f(words[i])];
    }

    for (int i = 10; i >= 0; --i) {
        prefix_sum[i] += prefix_sum[i + 1];
    }

    *returnSize = queriesSize;
    int *ans = (int *) calloc(queriesSize, sizeof(int));
    for (int i = 0; i < queriesSize; ++i) {
        ans[i] = prefix_sum[f(queries[i]) + 1];
    }

    return ans;
}

int main()
{
    char *queries[] = {"bbb", "cc"};
    char *words[] = {"a", "aa", "aaa", "aaaa"};
    int returnSize;
    int *ans = numSmallerByFrequency(queries, array_len(queries, char *),
                          words, array_len(words, char *), &returnSize);
    array_int_print(ans, returnSize);

    return 0;
}