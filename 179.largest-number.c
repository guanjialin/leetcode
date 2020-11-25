//
// Created by addzero on 2020/11/25.
//


#include "header.h"

#ifdef __SELF__
// 自己的解法。。。虽然思路一样，但是评论的解法实在是高
static int cmp(const void *_x, const void *_y)
{
    char *x = (char *) _x;
    char *y = (char *) _y;
    char px[21] = {0};
    char py[21] = {0};

    strcat(px, x);
    strcat(px, y);
    strcat(py, y);
    strcat(py, x);
    return strcmp(py, px);
}

static int itoa(char *dst, int num)
{
    if (0 == num) {
        dst[0] = '0';
        dst[1] = '\0';
        return 1;
    }

    int size = 0;
    int base = 1e9;

    while (0 == num / base) {
        base /= 10;
    }

    while (base > 0) {
        dst[size++] =  num / base + '0';
        num %= base;
        base /= 10;
    }
    dst[size++] = '\0';

    return size;
}

char * largestNumber(int* nums, int numsSize)
{
    char *ans = (char *) calloc(1024, sizeof(char));
    char num_str[numsSize][11];
    int num_str_size[numsSize];

    for (int i = 0; i < numsSize; ++i) {
        num_str_size[i] = itoa(num_str[i], nums[i]);
    }

    qsort(num_str, numsSize, sizeof(char) * 11, cmp);

    for (int i = 0; i < numsSize; ++i) {
        strcat(ans, num_str[i]);
    }

    return *ans == '0' ? "0" : ans;
}
#else
static int cmp(const void *_x, const void *_y)
{
    char x[21];
    char y[21];
    sprintf(x, "%d%d", *(int *)_x, *(int *)_y);
    sprintf(y, "%d%d", *(int *)_y, *(int *)_x);
    return strcmp(y, x);
}

char * largestNumber(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    char *ans = (char *) malloc(1001 * sizeof(char));
    char *p = ans;
    for (int i = 0; i < numsSize; ++i) {
        p += sprintf(p, "%d", nums[i]);
    }

    return *ans == '0' ? "0" : ans;
}
#endif

int main() {
    int nums[] = {3, 30, 34, 5, 9};
    printf("%s\n", largestNumber(nums, array_int_len(nums)));

    return 0;
}