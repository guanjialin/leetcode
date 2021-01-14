//
// Created by addzero on 2020/12/21.
//


#ifdef __LOCAL__
#include "header.h"
#endif

int coinChange(int* coins, int coinsSize, int amount){
    if (amount < 0) {
        return -1;
    } else if (!amount) {
        return 0;
    }

    int ans = INT_MAX;
    for (int i = 0; i < coinsSize; ++i) {
        int ans = coinChange(coins, coinsSize, amount - coins[i]);
        if (ans != -1) {
            ans = fmin(, ans) + 1;
        }
    }

    return ans;
}

#ifdef __LOCAL__
int main()
{

    
    return 0;
}
#endif