//
// Created by addzero on 2020/12/3.
//


#include "header.h"

int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination)
{
    int pos = 0;
    for (int i = start; i != destination; i = (i + 1) % distanceSize) {
        pos += distance[i];
    }

    int neg = 0;
    for (int i = destination; i != start; i = (i + 1) % distanceSize) {
        neg += distance[i];
    }

    return fmin(pos, neg);
}

int main()
{
    int data[] = {1, 2, 3, 4};
    printf("%d\n", distanceBetweenBusStops(data, array_int_len(data), 1, 0));

    return 0;
}