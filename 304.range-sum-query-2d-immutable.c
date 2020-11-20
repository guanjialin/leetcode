//
// Created by addzero on 2020/11/20.
//


#include "header.h"

/*
 * 多申请一行和一列占位，应该会更优雅
 */
typedef struct num_matrix
{
    int **matrix;
    int row;
    int col;
} NumMatrix;

static void build(int **matrix, int row, int col)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                matrix[i][j] += matrix[i][j - 1];
            } else if (j == 0) {
                matrix[i][j] += matrix[i - 1][j];
            } else {
                matrix[i][j] +=
                        matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
            }
        }
    }
}

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize)
{
    if (!matrix || !matrixSize || !matrixColSize) {
        return NULL;
    }

    struct num_matrix *obj = (struct num_matrix *) malloc(sizeof(struct num_matrix));
    obj->matrix = matrix;   // 作弊玩法，应该要复制过来才对的
    obj->row = matrixSize;
    obj->col = *matrixColSize;
    build(obj->matrix, obj->row, obj->col);

    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2)
{
    int ans = obj->matrix[row2][col2];

    if (row1 <= 0 && col1 <= 0) {
        return ans;
    } else if (row1 <= 0) {
        return  ans - obj->matrix[row2][col1 - 1];
    } else if (col1 <= 0) {
        return ans - obj->matrix[row1 - 1][col2];
    }

    return ans - obj->matrix[row2][col1 - 1] - obj->matrix[row1 - 1][col2]
            + obj->matrix[row1 - 1][col1 - 1];
}

void numMatrixFree(NumMatrix* obj) {
    free(obj);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);

 * numMatrixFree(obj);
*/

int main()
{
    int **matrix = (int **) malloc(5 * sizeof(int *));
    int col = 5;
    int matrix0[] = {3, 0, 1, 4, 2};
    int matrix1[] = {5, 6, 3, 2, 1};
    int matrix2[] = {1, 2, 0, 1, 5};
    matrix[0] = matrix0;
    matrix[1] = matrix1;
    matrix[2] = matrix2;

    struct num_matrix *obj = numMatrixCreate(matrix, 3, &col);
    printf("%d\n", numMatrixSumRegion(obj, 1, 1, 2, 2));

    return 0;
}