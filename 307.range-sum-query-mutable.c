//
// Created by addzero on 2020/11/20.
//


#include "header.h"


#ifdef __BIT__
// 基于树状数组实现
typedef struct num_array
{
    int *origin;
    int *data;
    int size;
} NumArray;


void numArrayUpdate(NumArray* obj, int index, int val);

NumArray* numArrayCreate(int* nums, int numsSize)
{
    struct num_array *obj = (struct num_array *) malloc(sizeof(struct num_array));
    obj->origin = (int *) calloc(numsSize, sizeof(int));
    obj->data = (int *) calloc(numsSize, sizeof(int));
    obj->size = numsSize;

    for (int i = 0; i < numsSize; ++i) {
        numArrayUpdate(obj, i, nums[i]);
        obj->origin[i] = nums[i];
    }

    return obj;
}

#define lowbit(x) (x & -x)

void numArrayUpdate(NumArray* obj, int index, int val)
{
    if (index < 0 || index > obj->size) {
        return;
    }

    int delta = val - obj->origin[index];
    for (int i = index + 1; i <= obj->size; i += lowbit(i)) {
        obj->data[i - 1] += delta;
    }
    obj->origin[index] = val;
}

static int numArraySum(NumArray* obj, int idx)
{
    int sum = 0;

    for (int x = idx + 1; x > 0; x -= lowbit(x)) {
        sum += obj->data[x - 1];
    }

    return sum;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    int sum = 0;

    if (i < 0 || j < 0 || i >= obj->size || j >= obj->size) {
        return - 1;
    }

    return numArraySum(obj, j) - numArraySum(obj, i) + obj->origin[i];
}

void numArrayFree(NumArray* obj) {
    free(obj->data);
    free(obj);
}
#elif __RECURSION__
// 基于线段树递归实现
typedef struct num_array
{
    int *tree;
    int size;   // size of nums, ** not tree size **;
} NumArray;


static void build_tree(int *tree, int *nums, int size, int node, int left, int right)
{
    if (left >= right) {
        if (left == right) {
            tree[node] = nums[left];
        }
        return;
    }

    int mid = left + (right - left) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;

    build_tree(tree, nums, size, left_node, left, mid);
    build_tree(tree, nums, size, right_node, mid + 1, right);
    tree[node] = tree[left_node] + tree[right_node];
}

NumArray* numArrayCreate(int* nums, int numsSize) {
    struct num_array *obj = (struct num_array *) malloc(sizeof(struct num_array));
    obj->tree = (int *) calloc(numsSize * 4, sizeof(int));
    obj->size = numsSize;

    build_tree(obj->tree, nums, numsSize, 0, 0, numsSize - 1);

    return obj;
}

static void update(int *tree, int node, int left, int right, int index, int val)
{
    if (left == right) {
        tree[node] = val;
        return;
    }

    int mid = left + (right - left) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;

    if (index <= mid) {
        update(tree, left_node, left, mid, index, val);
    } else {
        update(tree, right_node, mid + 1, right, index, val);
    }
    tree[node] = tree[left_node] + tree[right_node];
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    update(obj->tree, 0, 0, obj->size - 1, index, val);
}

static int query(int *tree, int node, int left, int right, int L, int R)
{
    if (R < left || L > right) {
        return 0;
    } else if ((L <= left && R >= right) || left == right) {
        return tree[node];
    }

    int mid = left + (right - left) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;
    int sum_left = query(tree, left_node, left, mid, L, R);
    int sum_right = query(tree, right_node, mid + 1, right, L, R);

    return sum_left + sum_right;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    return query(obj->tree, 0, 0, obj->size - 1, i, j);
}

void numArrayFree(NumArray* obj) {
    free(obj->tree);
    free(obj);
}
#else
// 基于线段树迭代实现
typedef struct num_array {
    int *data;
    int size;
} NumArray;


static void build_tree(int *tree, int *nums, int numsSize)
{
    memcpy(tree + numsSize, nums, sizeof(int) * numsSize);

    for (int i = numsSize - 1; i > 0; --i) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

NumArray* numArrayCreate(int* nums, int numsSize) {
    struct num_array *obj = (struct num_array *) malloc(sizeof(struct num_array));
    obj->size = numsSize;
    obj->data = (int *) calloc(numsSize * 2, sizeof(int));
    build_tree(obj->data, nums, numsSize);

    return obj;
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    int delta = val - obj->data[obj->size + index];

    for (int i = obj->size + index; i > 0; i /= 2) {
        obj->data[i] += delta;
    }
}

int numArraySumRange(NumArray* obj, int l, int r) {
    l += obj->size;
    r += obj->size;
    int sum = 0;

    while (l <= r) {
        // l 如果是左节点，说明左右都需要，则直接加父节点即可；
        // l 如果是右节点，说明左是不需要的，则赶紧加上自己，然后往父节点的兄弟走
        // r 同理
        sum += l % 2 ? obj->data[l++] : 0;
        sum += 0 == r % 2 ? obj->data[r--] : 0;
        l /= 2;
        r /= 2;
    }
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj->data);
    free(obj);
}
#endif

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, i, val);

 * int param_2 = numArraySumRange(obj, i, j);

 * numArrayFree(obj);
*/


int main()
{
    int nums[] = {2, 4, 5, 7, 8, 9};
    struct num_array *obj = numArrayCreate(nums, array_int_len(nums));
    numArrayUpdate(obj, 4, 6);
    numArrayUpdate(obj, 0, 2);
    numArrayUpdate(obj, 0, 9);
    printf("%d\n", numArraySumRange(obj, 4, 4));
    printf("%d\n", numArraySumRange(obj, 0, 4));
    numArrayUpdate(obj, 1, 2);
    printf("%d\n", numArraySumRange(obj, 0, 2));
    numArrayFree(obj);

    return 0;
}