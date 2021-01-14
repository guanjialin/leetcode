//
// Created by addzero on 2021/1/13.
//


#ifdef __LOCAL__

#include "header.h"

#endif

#if 0
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        while (numBottles >= numExchange) {
            ans += numBottles / numExchange;
            numBottles = numBottles / numExchange + numBottles % numExchange;
        }

        return ans;
    }
};
#else
// 答案 O(1) 解法
// numB - n(numE - 1) < numE
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles >= numExchange ? (numBottles - numExchange) / (numExchange - 1) + 1 + numBottles : numBottles;
    }
};
#endif

#ifdef __LOCAL__

int main() {
    cout << Solution().numWaterBottles(9, 3) << endl;
    cout << Solution().numWaterBottles(15, 4) << endl;
    cout << Solution().numWaterBottles(5, 5) << endl;
    cout << Solution().numWaterBottles(2, 3) << endl;

    return 0;
}

#endif