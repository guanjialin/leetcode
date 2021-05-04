//
// Created by addzero on 2021/5/4.
//


#ifdef __LOCAL__

#include "header.h"

#endif

class Solution {
public:
    string solveEquation(string equation) {
        int idx = 0;
        int sum = 0;
        int x_num = 0;
        int direction = -1;
        int ch_direction = 1;

        while (idx < equation.size()) {
            switch (equation[idx]) {
                case 'x':
                    x_num += ch_direction * -1 * direction;
                    break;
                case '+':
                case '=':
                case '-':
                    ch_direction = equation[idx] == '-' ? -1 : 1;
                    direction = equation[idx] == '=' ? 1 : direction;
                    break;
                default:
                    // 遇到了数字，算出数字值
                    int cur = 0;
                    while (idx < equation.size() && equation[idx] >= '0' && equation[idx] <= '9') {
                        cur = cur * 10 + (equation[idx] - '0');
                        ++idx;
                    }

                    // [num]x 的情况
                    if (equation[idx] == 'x') {
                        x_num += ch_direction * -1 * direction * cur;;
                    } else {
                        sum += direction * ch_direction * cur;
                        --idx;
                    }
            }

            ++idx;
        }

        if (!x_num && !sum) return "Infinite solutions";
        return !x_num ? "No solution" : "x=" + std::to_string(sum / x_num);
    }
};

#ifdef __LOCAL__

int main() {
    cout << Solution().solveEquation("2x+3x-6x=x+2") << endl;

    return 0;
}

#endif