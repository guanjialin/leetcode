//
// Created by addzero on 2020/11/25.
//


#include "header.h"

int maxProfit(int* prices, int pricesSize)
{
    int ans = 0;
    int min_prices = INT_MAX;

    for (int i = 0; i < pricesSize; ++i) {
        ans = fmax(ans, prices[i] - min_prices);
        min_prices = fmin(min_prices, prices[i]);
    }

    return ans;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(prices, array_int_len(prices)));

    return 0;
}