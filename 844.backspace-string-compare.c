//
// Created by dell on 2020/10/27.
//

// 还是不太会

#include "header.h"

bool backspaceCompare(char * S, char * T)
{
    int siter = strlen(S) - 1, titer = strlen(T) - 1;
    int sback = 0, tback = 0;

    while (siter >= 0 || titer >= 0) {
        while (siter >= 0) {
            if (S[siter] == '#') {
                ++sback;
                --siter;
            } else if (sback > 0) {
                --sback;
                --siter;
            } else {
                break;
            }
        }

        while (titer >= 0) {
            if (T[titer] == '#') {
                ++tback;
                --titer;
            } else if (tback > 0){
                --tback;
                --titer;
            } else {
                break;
            }
        }

        if (titer >= 0 && siter >= 0) {
            if (S[siter] != T[titer]) {
                return false;
            }
        } else if (siter >= 0 || titer >= 0) {
            return false;
        }

        --siter;
        --titer;
    }

    return true;
}

int main()
{
    printf("%d\n", backspaceCompare("bxj##tw", "bxo#j##tw"));   // 1
    printf("%d\n", backspaceCompare("ab#c", "ad#c"));   // 1
    printf("%d\n", backspaceCompare("ab##", "c#d#"));   // 1
    printf("%d\n", backspaceCompare("a##c", "#a#c"));   // 1
    printf("%d\n", backspaceCompare("a#c", "b"));       // 0
    printf("%d\n", backspaceCompare("xywrrmp", "xywrrmu#p"));       // 1

    return 0;
}