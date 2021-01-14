//
// Created by addzero on 2021/1/7.
//


#ifdef __LOCAL__
#include "header.h"
#endif

#ifdef __BFS__
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        queue<int> q;
        int row_size = isConnected.size();
        int col_size = isConnected[0].size();

        for (int row = 0; row < row_size; ++row) {
            if (isConnected[row][row] != 1) continue;

            q.push(row);
            while (!q.empty()) {
                auto node = q.front(); q.pop();
                for (int i = 0; i < col_size; ++i) {
                    if (1 == isConnected[node][i]) {
                        isConnected[node][i] = isConnected[i][node]
                                = isConnected[1][1] = 2;
                        q.push(i);
                    }
                }
            }
            ++ans;
        }

        return ans;
    }
};
#else
// dfs 做法
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;

        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[i][i] == 1) {
                ++ans;
                dfs(isConnected, i);
            }
        }

        return ans;
    }

private:
    void dfs(vector<vector<int>> &isConnected, int row) {
        for (int i = 0; i < isConnected[row].size(); ++i) {
            if (isConnected[row][i] == 1) {
                isConnected[i][i] = isConnected[i][row] = isConnected[row][i] = 2;
                dfs(isConnected, i);
            }
        }
    }
};
#endif

#ifdef __LOCAL__
int main()
{
    vector<vector<int>> isConnected = {
            {1,0,0,1}, {0,1,1,0}, {0,1,1,1},{1,0,1,1}
    };
    cout << Solution().findCircleNum(isConnected) << endl;
    
    return 0;
}
#endif