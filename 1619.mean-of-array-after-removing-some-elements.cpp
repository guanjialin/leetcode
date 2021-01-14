//
// Created by addzero on 2021/1/8.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    double trimMean(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int percent5 = arr.size() * 0.05;
        return std::accumulate(arr.begin() + percent5, arr.end() - percent5, 0) / (arr.size() * 0.9);
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> arr = {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3};
    cout << Solution().trimMean(arr) << endl;

    return 0;
}

#endif