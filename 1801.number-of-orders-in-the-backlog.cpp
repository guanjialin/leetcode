//
// Created by addzero on 2021/4/23.
//


#ifdef __LOCAL__

#include "header.h"

#endif

const int TYPE_BUY = 0;
const int TYPE_SELL = 1;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // 销售订单需维护小根堆, pair<price, amount>
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq_sell;
        // 采购订单需维护大根堆
        priority_queue<pair<int, int>> pq_buy;
        long ans = 0;

        for (const auto &order : orders) {
            int price = order[0], amount = order[1], type = order[2];

            if (type == TYPE_BUY) {
                while (!pq_sell.empty() && pq_sell.top().first <= price && amount > 0) {
                    auto top = pq_sell.top();
                    pq_sell.pop();
                    if (top.second > amount) {
                        pq_sell.push({top.first, top.second - amount});
                        ans -= amount;
                        amount = 0;
                    } else {
                        amount -= top.second;
                        ans -= top.second;
                    }
                }

                if (pq_sell.empty() || pq_sell.top().first > price) {
                    pq_buy.push({price, amount});
                    ans += amount;
                }
            } else {
                while (!pq_buy.empty() && pq_buy.top().first >= price && amount > 0) {
                    auto top = pq_buy.top();
                    pq_buy.pop();
                    if (top.second > amount) {
                        pq_buy.push({top.first, top.second - amount});
                        ans -= amount;
                        amount = 0;
                    } else {
                        amount -= top.second;
                        ans -= top.second;
                    }
                }

                if (pq_buy.empty() || pq_buy.top().first < price) {
                    pq_sell.push({price, amount});
                    ans += amount;
                }
            }
        }

        return ans % 1000000007;
    }
};

#ifdef __LOCAL__

int main() {
    vector<vector<int>> orders = {
            {26, 7, 0}, {16, 1, 1}, {14, 20, 0}, {23, 15, 1}, {24, 26, 0}, {19, 4, 1}, {1, 1, 0},
    };
    cout << Solution().getNumberOfBacklogOrders(orders) << endl;


    return 0;
}

#endif