//
// Created by addzero on 2021/1/6.
//


#ifdef __LOCAL__
#include "header.h"
#endif

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    int ans = 0;

    for (int i = 0; i < timeSeriesSize; ++i) {
        if (i + 1 == timeSeriesSize || timeSeries[i + 1] >= timeSeries[i] + duration) {
            ans += duration;
        } else {
            ans += (timeSeries[i + 1] - timeSeries[i]);
        }
    }

    return ans;
}

#ifdef __LOCAL__
int main()
{
    int timeSeries[] = {1, 4};
    printf("%d\n", findPoisonedDuration(timeSeries, array_int_len(timeSeries), 2));
    
    return 0;
}
#endif