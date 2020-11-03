//
// Created by dell on 2020/11/3.
//

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "header.h"

static bool match(const char *query, const char *pattern)
{
    while (*query != '\0' && *pattern != '\0') {
        if (*query == *pattern) {
            ++query;
            ++pattern;
        } else if (islower(*query)) {
            ++query;
        } else {
            return false;
        }
    }

    while (*query != '\0') {
        if (isupper(*query++)) {
            return  false;
        }
    }

    return *pattern == '\0';
}

bool* camelMatch(char ** queries, int queriesSize, char * pattern, int* returnSize){
    bool *ans = (bool *) malloc(queriesSize * sizeof(char));
    *returnSize = 0;

    for (int i = 0; i < queriesSize; ++i) {
        ans[(*returnSize)++] = match(queries[i], pattern);
    }

    return ans;
}

int main()
{
    int returnSize;
    char *queries[] = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    bool *ans = camelMatch(queries, array_len(queries, char *), "FB", &returnSize);
    array_int_print(ans,  returnSize);

    return 0;
}