//
// Created by addzero on 2020/11/27.
//


#include "cppheader.h"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        visited.insert(0);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto room : rooms[cur]) {
                if (!visited.count(room)) {
                    visited.insert(room);
                    q.push(room);
                }

            }
        }

        return visited.size() == rooms.size();
    }
};

int main() {
    vector<vector<int>> rooms = {
            {1}, {2}, {3}, {}
    };
    cout << Solution().canVisitAllRooms(rooms) << endl;

    return 0;
}