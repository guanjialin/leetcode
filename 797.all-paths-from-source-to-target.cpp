//
// Created by addzero on 2020/11/27.
//


#include "cppheader.h"

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size() - 1;
        path.emplace_back(0);
        dfs(graph, 0);

        return ans;
    }

private:
    void dfs(vector<vector<int>> &graph, int cur)
    {
        if (target == cur) {
            ans.emplace_back(path);
            return;
        }

        for (auto i = 0; i < graph[cur].size(); ++i) {
            path.emplace_back(graph[cur][i]);
            dfs(graph, graph[cur][i]);
            path.pop_back();
        }
    }

private:
    int target;
    vector<int> path;
    vector<vector<int>> ans;
};

int main() {
    vector<vector<int>> graph = {
            {1, 2}, {3}, {3}, {}
    };
    auto ans = Solution().allPathsSourceTarget(graph);
    for (const auto &path : ans) {
        vector_print(path);
    }

    return 0;
}