//
// Created by dell on 2020/10/31.
//

#include "header.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(char *record, int recordSize, char **ans, int *returnSize, int left, int right, int n)
{
    if (recordSize == 2 * n) {
        if (left == n && right == n) {
            ans[*returnSize] = (char *) calloc(recordSize + 1, sizeof(char));
            memcpy(ans[*returnSize], record, sizeof(char) * recordSize);
            ++(*returnSize);
        }
        return;
    }

    if (left < 4) {
        record[recordSize] = '(';
        dfs(record, recordSize + 1, ans, returnSize, left + 1, right, n);
    }
    if (left > right) {
        record[recordSize] = ')';
        dfs(record, recordSize + 1, ans, returnSize, left, right + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize)
{
    char **ans = (char **) malloc(1024 * sizeof(char *));
    *returnSize = 0;
    char record[n * 2];
    memset(record, 0x00, sizeof(char) * n * 2);
    dfs(record, 0, ans, returnSize, 0, 0, n);

    return ans;
}

int main()
{
    int returnSize;
    char **ans = generateParenthesis(3, &returnSize);
    array_print(ans, returnSize, "%s\n");

    return 0;
}