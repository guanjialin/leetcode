//
// Created by addzero on 2021/5/4.
//


#ifdef __LOCAL__

#include "header.h"

#endif

/* BFS 解法
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> relation;

        for (int i = 0; i < manager.size(); ++i) {
            if (i == headID) continue;
            relation[manager[i]].push_back(i);
        }

        int ans = 0;
        queue<int> q;
        q.push(headID);
        unordered_map<int, int> time;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front(); q.pop();
                for (auto child : relation[cur]) {
                    q.push(child);
                    time[child] = time[cur] + informTime[cur];
                    ans = std::max(time[child], ans);
                }
            }
        }

        return ans;
    }
};
 */
/* DFS 解法
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < manager.size(); ++i) {
            if (i == headID) continue;
            relation[manager[i]].push_back(i);
        }

        return dfs(headID, manager, informTime, 0);
    }

private:
    int dfs(int cur, const vector<int> &manager, const vector<int> &informTime, int curTime) {
        int ans = curTime;
        int nextTime = curTime + informTime[cur];
        for (auto child : relation[cur]) {
            ans = std::max(ans, dfs(child, manager, informTime, nextTime));
        }

        return ans;
    }

private:
    unordered_map<int, vector<int>> relation;
};
 */

// 并查集思路解法
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;

        for (int i = 0; i < manager.size(); ++i) {
            if (informTime[i]) continue;

            int cur = 0;
            int parent = manager[i];
            while (parent != -1) {
                cur += informTime[parent];
                parent = manager[parent];
            }

            ans = std::max(cur, ans);
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<int> manager = {-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6};
    vector<int> informTime = {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0};
    cout << Solution().numOfMinutes(15, 0, manager, informTime) << endl;

    return 0;
}

#endif