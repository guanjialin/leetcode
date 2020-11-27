//
// Created by addzero on 2020/11/27.
//


#include "../cppheader.h"

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        queue<int> q;
        unordered_set<int> visited;
        unordered_map<int, unordered_set<int>> map_vertex;

        // 将节点预处理成类邻接表，方便后续查找
        for (const auto &edge : graph) {
            // 有辅助 visited ，自环也无所谓
            map_vertex[edge[0]].insert(edge[1]);
        }

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (const auto &vertex : map_vertex[cur]) {
                if (vertex == target) {
                    return true;
                }
                visited.insert(vertex);
                q.push(vertex);
            }
        }

        return false;
    }
};

int main() {
    vector<vector<int>> graph = {{0, 1}, {0, 2}, {1, 2}, {1, 2}};
    cout << Solution().findWhetherExistsPath(3, graph, 0, 2) << endl;
    cout << Solution().findWhetherExistsPath(3, graph, 0, 3) << endl;

    return 0;
}