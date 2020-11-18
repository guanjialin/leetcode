//
// Created by addzero on 2020/11/18.
//


#include "header.h"

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    int min_index = 0;
    int min_val = INT_MAX;
    int remain = 0;

    for (int i = 0; i < gasSize; ++i) {
        remain += gas[i] - cost[i];
        if (remain < min_val) {
            min_val = remain;
            min_index = i;
        }
    }

    return remain >= 0 ? (min_index + 1) % gasSize : -1;
}

int main() {
    int gas[] = {1, 2, 3, 4, 5};
    int cost[] = {3, 4, 5, 1, 2};
    printf("%d\n", canCompleteCircuit(gas, 5, cost, 5));

    return 0;
}