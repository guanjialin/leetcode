//
// Created by addzero on 2020/11/23.
//


#include "header.h"

#if 0
static int cmp(const void *x, const void *y)
{
    return **(int **) x - **(int **)y;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize)
{
    qsort(points, pointsSize, sizeof(int*), cmp);
    int right = INT_MAX;
    int ans = 0;

    for (int i = 0; i < pointsSize; ++i) {
        if (points[i][0] <= right) {
            right = fmin(right, points[i][1]);
        } else {
            ++ans;
            right = points[i][1];
        }
    }

    return pointsSize > 0 ? ans + 1 : 0;
}
#else
// 答案做法更胜一筹
static int cmp(void* _a, void* _b) {
    int *a = *(int**)_a, *b = *(int**)_b;
    return a[1] < b[1] ? -1 : 1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if (!pointsSize) {
        return 0;
    }
    qsort(points, pointsSize, sizeof(int*), cmp);
    int pos = points[0][1];
    int ans = 1;
    for (int i = 0; i < pointsSize; ++i) {
        if (points[i][0] > pos) {
            pos = points[i][1];
            ++ans;
        }
    }
    return ans;
}
#endif

int main()
{
    int **points = (int **) malloc(4 * sizeof(int *));
    int col = 2;
    int point0[] = {2, 6};
    int point1[] = {3, 4};
    int point2[] = {5, 7};
    int point3[] = {7, 8};
    points[0] = point0;
    points[1] = point1;
    points[2] = point2;
    points[3] = point3;
    printf("%d\n", findMinArrowShots(points, 4, &col));

    return 0;
}