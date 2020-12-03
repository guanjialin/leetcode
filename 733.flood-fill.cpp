//
// Created by addzero on 2020/12/3.
//


#ifdef __LOCAL__

#include "cppheader.h"

#endif

// 答案解法太妙了，省掉 visited
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int origin = image[sr][sc];
        if (origin == newColor) {
            return image;
        }

        int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;

        while (!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for (auto & i : direction) {
                int new_row = row + i[0];
                int new_col = col + i[1];
                if (new_row < 0 || new_col < 0
                        || new_row >= image.size() || new_col >= image[0].size()
                        || image[new_row][new_col] != origin) {
                    continue;
                }
                q.push({new_row, new_col});
                image[new_row][new_col] = newColor;
            }
        }

        return image;
    }
};

#ifdef __LOCAL__

int main()
{


    return 0;
}

#endif