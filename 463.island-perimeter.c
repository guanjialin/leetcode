//
// Created by addzero on 2020/12/3.
//


#ifdef __LOCAL__

#include "header.h"

#endif

int islandPerimeter(int** grid, int gridSize, int* gridColSize)
{
    int ans = 0;
    int direction[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            if (grid[i][j]) {
                int perimeter = 4;
                for (int k = 0; k < 4; ++k) {
                    int row = i + direction[k][0];
                    int col = j + direction[k][1];
                    // 校验
                    if (row < 0 || col < 0 || row >= gridSize || col >= *gridColSize) {
                        continue;
                    }
                    perimeter -= grid[row][col];
                }
                ans += perimeter;
            }
        }
    }

    return ans;
}

#ifdef __LOCAL__

int main() {
    int **data = (int **) calloc(4, sizeof(int *));
    int data0[] = {0,1,0,0};
    int data1[] = {1,1,1,0};
    int data2[] = {0,1,0,0};
    int data3[] = {1,1,0,0};
    data[0] = data0;
    data[1] = data1;
    data[2] = data2;
    data[3] = data3;
    int colsize = 4;
    printf("%d\n", islandPerimeter(data, 4, &colsize));

    return 0;
}

#endif