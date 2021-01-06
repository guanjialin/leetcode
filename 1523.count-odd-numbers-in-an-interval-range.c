//
// Created by addzero on 2021/1/6.
//


#ifdef __LOCAL__
#include "header.h"
#endif

int countOdds(int low, int high){
    return (high - low) / 2 + (low % 2 || high % 2);
}

#ifdef __LOCAL__
int main()
{
    printf("%d\n", countOdds(3, 7));
    
    return 0;
}
#endif