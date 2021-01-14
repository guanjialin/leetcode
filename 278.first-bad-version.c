//
// Created by addzero on 2020/12/10.
//


#ifdef __LOCAL__

#include "header.h"

#endif

// The API isBadVersion is defined for you.
#ifdef __LOCAL__
bool isBadVersion(int version);
#endif

int firstBadVersion(int n) {
    int left = 1, right = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

#ifdef __LOCAL__

int main() {


    return 0;
}

#endif