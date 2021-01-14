//
// Created by addzero on 2021/1/14.
//


#ifdef __LOCAL__

#include "header.h"

#endif

// 评论区大佬的解法：找战舰头。
// 自己一直在想着找战舰尾，一直没搞出来
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'X' && (!i || board[i - 1][j] == '.') && (!j || board[i][j - 1] == '.')) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};

#ifdef __LOCAL__

int main() {
    vector<vector<char>> board = {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    cout << Solution().countBattleships(board) << endl;

    return 0;
}

#endif