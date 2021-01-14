//
// Created by addzero on 2020/12/31.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;

        for (int i = prices.size() - 1; i >= 0; --i) {
            while (!stk.empty() && prices[i] < stk.top()) {
                stk.pop();
            }
            int temp = prices[i];
            prices[i] = stk.empty() ? prices[i] : prices[i] - stk.top();
            stk.push(temp);
        }

        return prices;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> prices = {8,4,6,2,3};
    vector_print(Solution().finalPrices(prices));

    return 0;
}

#endif