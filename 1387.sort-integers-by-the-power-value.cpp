//
// Created by addzero on 2020/11/27.
//


#include "cppheader.h"

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> data(hi - lo + 1);

        // 计算 weight
        for (int i = lo; i <= hi; ++i) {
            data[i - lo] = i;
        }

        std::sort(data.begin(), data.end(), [&](int x, int y) {
            return cal_weight(x) == cal_weight(y) ? x < y : cal_weight(x) < cal_weight(y);
        });

        return data[k - 1];
    }

private:
    inline int cal_weight(int val)
    {
        return map_weight.count(val)
            ? map_weight[val] : (map_weight[val] = 1 + (val % 2 ? cal_weight(3 * val + 1) : cal_weight(val / 2)));
    }

private:
    unordered_map<int, int> map_weight = {{1, 0}};
};

int main() {
    cout << Solution().getKth(1, 1000, 777) << endl;

    return 0;
}