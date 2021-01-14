//
// Created by addzero on 2021/1/8.
//


#ifdef __LOCAL__

#include "header.h"

#endif

struct PairHash
{
    size_t operator() (const std::pair<int, int> &p) const {
        return (long) p.first << 30 | p.second;
    }
};

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int cur_x = 0, cur_y = 0;
        int width = 0, height = 0;
        unordered_set<pair<int, int>, PairHash> pos = {{0, 0}};

        for (auto c : command) {
            if ('U' == c) {
                ++cur_y;
                ++height;
            } else if ('R' == c) {
                ++cur_x;
                ++width;
            }
            pos.insert({cur_x, cur_y});
        }

        if (!pos.count({x, y}) && !pos.count({x % width, y - x / width * height})) {
            return false;
        }

        for (const auto &obstacle : obstacles) {
            if (obstacle[0] <= x && obstacle[1] <= y
                && (pos.count({obstacle[0], obstacle[1]})
                    || pos.count({obstacle[0] % width, obstacle[1] - obstacle[0] / width * height}))) {
                return false;
            }
        }

        return true;
    }
};

#ifdef __LOCAL__

int main() {
    vector<vector<int>> obstacles = {{2, 2}};
    cout << Solution().robot("URR", obstacles, 3, 2) << endl;

    return 0;
}

#endif