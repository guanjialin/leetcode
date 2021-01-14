//
// Created by addzero on 2020/11/4.
//


#include "header/cppheader.h"

// TODO 这道题最好的做法应该是用 unordered_set，但是不懂 pair 作为 key 如何自定义 hash，故暂时先用 set 吧
class Solution {
public:
    bool isPathCrossing(string path) {
        int horizontal = 0, vertical = 0;
        set<pair<int, int>> set_position;
        set_position.insert(std::make_pair(0, 0));

        for (auto c : path) {
            switch (c) {
                case 'N': ++vertical; break;
                case 'S': --vertical; break;
                case 'W': --horizontal; break;
                case 'E': ++horizontal; break;
            }

            if (set_position.find(std::make_pair(horizontal, vertical)) != set_position.end()) {
                return true;
            }

            set_position.insert(std::make_pair(horizontal, vertical));
        }

        return false;
    }
};

int main() {
    cout << Solution().isPathCrossing("NESWW") << endl;
    cout << Solution().isPathCrossing("NES") << endl;

    return 0;
}