//
// Created by addzero on 2021/1/6.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2){
            return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
        });

        int size = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[size][1] >= intervals[i][0]) {
                intervals[size][1] = max(intervals[size][1], intervals[i][1]);
            } else {
                intervals[++size] = intervals[i];
            }
        }
        intervals.resize(size + 1);

        return intervals;
    }
};

#ifdef __LOCAL__

int main() {
    vector<vector<int>> intervals = {
            {1, 3}, {2, 6}, {8, 10}, {15,18},
    };
    auto ans = Solution().merge(intervals);
    for (auto item : intervals) {
        cout << "[" << item[0] << "," << item[1] << "]" << endl;
    }

    return 0;
}

#endif