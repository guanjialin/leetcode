//
// Created by addzero on 2021/1/4.
//


#ifdef __LOCAL__
#include "header.h"
#endif

bool threeConsecutiveOdds(int* arr, int arrSize){
    if (arrSize < 3) {
        return false;
    }
    int odd = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] % 2) {
            if (++odd == 3) {
                return true;
            }
        } else {
            odd = 0;
        }
    }

    return false;
}

#ifdef __LOCAL__
int main()
{
    int data[] = {1,2,34,3,4,5,7,23,12};
    printf("%d\n", threeConsecutiveOdds(data, array_int_len(data)));
    
    return 0;
}
#endif