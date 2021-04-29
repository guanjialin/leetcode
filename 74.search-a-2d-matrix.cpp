//
// Created by addzero on 2021/4/29.
//


#ifdef __LOCAL__

#include "header.h"

#endif

struct cmp {
    bool operator()(int target, const vector<int> &line) {
        return target < line.front();
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix.front().front()) {
            return false;
        }

        auto row = --std::upper_bound(matrix.begin(), matrix.end(), target, cmp());

        return std::binary_search(row->begin(), row->end(), target);
    }
};

#ifdef __LOCAL__

int main() {
    vector<vector<int>> matrix = {
            {1,3,5,7}, {10,11,16,20}, {23,30,34,60}
    };
    cout << Solution().searchMatrix(matrix, 3) << endl;
    cout << Solution().searchMatrix(matrix, 2) << endl;
    cout << Solution().searchMatrix(matrix, 9) << endl;

    return 0;
}

#endif