//
// Created by addzero on 2021/1/2.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) {
            return arr;
        }

        vector<pair<int, int>> all;
        all.reserve(arr.size());

        for (int i = 0; i < arr.size(); ++i) {
            all.emplace_back(arr[i], i);
        }
        std::sort(all.begin(), all.end());

        arr[all[0].second] = 1;
        for (int i = 1; i < all.size(); ++i) {
            if (all[i].first == all[i - 1].first) {
                arr[all[i].second] = arr[all[i - 1].second];
            } else {
                arr[all[i].second] = arr[all[i - 1].second] + 1;
            }
        }

        return arr;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> arr = {40,10,20,30};
    vector_print(Solution().arrayRankTransform(arr));

    return 0;
}

#endif