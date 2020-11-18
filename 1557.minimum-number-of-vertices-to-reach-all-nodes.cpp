//
// Created by addzero on 2020/11/18.
//


#include "cppheader.h"

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> set_vertex;

        for (int i = 0; i < n; ++i) {
            set_vertex.insert(i);
        }

        for (auto edge : edges) {
            set_vertex.erase(edge[1]);
        }

        return vector<int>(set_vertex.begin(), set_vertex.end());
    }
};

int main()
{
    vector<vector<int>> edges = {
            {0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}
    };
    auto ans = Solution().findSmallestSetOfVertices(6, edges);
    for (auto n : ans) {
        cout << n << '\t';
    }
    cout << endl;

    return 0;
}