//
// Created by addzero on 2020/12/9.
//


#ifdef __LOCAL__

#include "header.h"

#endif

void duplicateZeros(int* arr, int arrSize)
{
    int i = 0;
    int zero_num = 0;

    for (; i < arrSize - zero_num; ++i) {
        zero_num += !arr[i];
    }


    if (arrSize - --i == zero_num && !arr[i]) {
        arr[--arrSize] = 0;
        --i;
    }

    for (int j = i; j >= 0; --j, --i) {
        arr[--arrSize] = arr[i];
        if (!arr[i]) {
            arr[--arrSize] = 0;
        }
    }
}

#ifdef __LOCAL__

int main() {
    int data[] = {1,0,2,3,0,0,5,0};
    duplicateZeros(data, array_int_len(data));
    array_int_print_all(data);

    return 0;
}

#endif