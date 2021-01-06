//
// Created by addzero on 2021/1/6.
//


#ifdef __LOCAL__
#include "header.h"
#endif

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_set<int> visited;
        unordered_map<int, vector<int>> indegree;   // 入度
        unordered_map<int, vector<int>> outdegree;  // 出度

        for (const auto &conn : connections) {
            outdegree[conn[0]].push_back(conn[1]);
            indegree[conn[1]].push_back(conn[0]);
        }

        int ans = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            auto node = q.front(); q.pop();
            visited.insert(node);

            for (auto ele : outdegree[node]) {
                if (!visited.count(ele)) {
                    q.push(ele);
                    ++ans;
                }
            }
            for (auto ele : indegree[node]) {
                if (!visited.count(ele)) {
                    q.push(ele);
                }
            }
        }

        return ans;
    }
};

#ifdef __LOCAL__
int main()
{
    vector<vector<int>> connections = {
            {0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}
    };
    cout << Solution().minReorder(6, connections) << endl;
    
    return 0;
}
#endif