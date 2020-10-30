//
// Created by lenovo on 2020/10/30.
//

#include "header.h"

bool judgeCircle(char * moves)
{
    int vertical = 0, horizontal = 0;

    while (*moves != '\0') {
        switch (*moves) {
            case 'R':
                ++horizontal;
                break;
            case 'L':
                --horizontal;
                break;
            case 'U':
                ++vertical;
                break;
            case 'D':
                --vertical;
                break;
        }
        ++moves;
    }

    return !vertical && !horizontal;
}

int main()
{
    printf("%d\n", judgeCircle("UD"));

    return 0;
}