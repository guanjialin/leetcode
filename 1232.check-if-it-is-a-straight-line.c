//
// Created by addzero on 2020/12/9.
//


#ifdef __LOCAL__

#include "header.h"

#endif

/*
 * 叉乘 a * b
 * = | x1, y1 | = x1 * y2 - y1 * x2
 *   | x2, y2 |
 * 若结果小于 0，表示向量 b 在向量 a 的顺时针方向；
 * 若结果大于 0，表示向量 b 在向量 a 的逆时针方向；
 * 若结果为 0，表示向量 b 与向量 a 平行；
 */
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize)
{
    int x1 = coordinates[1][0] - coordinates[0][0];
    int y1 = coordinates[1][1] - coordinates[0][1];

    for (int i = 2; i < coordinatesSize; ++i) {
        int x2 = coordinates[i][0] - coordinates[0][0];
        int y2 = coordinates[i][1] - coordinates[0][1];
        if (x1 * y2 != x2 * y1) {
            return false;
        }
    }

    return true;
}

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif