//
// Created by dell on 2020/10/22.
//

#include "header.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* partitionLabels(char * S, int* returnSize)
{
    size_t len = strlen(S  );
    int position[26] = {0};
    int *ans = (int *) calloc(26, sizeof(int));
    *returnSize = 0;

    // 记录下每种字母最开始出现和最后出现的位置
    for (int i = 0; i < len; ++i) {
        position[S[i] - 'a'] = i;
    }

    int left = 0, right = 0, cur = 0;
    while (cur < len) {
        right = position[S[cur] - 'a'];
        while (cur < right) {
            if (position[S[cur] - 'a'] > right) {
                right = position[S[cur] - 'a'];
            }
            ++cur;
        }
        ans[(*returnSize)++] = right - left + 1;
        left = right + 1;
        cur = right + 1;
    }

    return ans;
}

int main()
{
    int size;
    int *ans = partitionLabels("caedbdedda", &size);
    array_int_print(ans, size);

    ans = partitionLabels("ababcbacadefegdehijhklij", &size);
    array_int_print(ans, size);

    return 0;
}