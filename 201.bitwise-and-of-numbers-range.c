//
// Created by addzero on 2020/12/31.
//


#ifdef __LOCAL__
#include "header.h"
#endif

#if 0
int rangeBitwiseAnd(int m, int n)
{
    unsigned int i = m, ans = m;
    for (i = m; i <= n && (i & m); ++i) {
        ans &= i;
    }

    return i > n ? ans : 0;
}
#elif 0
int rangeBitwiseAnd(int m, int n)
{
    int shift = 0;
    while (m < n) {
        m >>= 1;
        n >>= 1;
        ++shift;
    }

    return m << shift;
}
#else
int rangeBitwiseAnd(int m, int n)
{
    while (n > m) {
        n &= n-1;
    }
    return n;
}
#endif

#ifdef __LOCAL__
int main()
{
    printf("%d\n", rangeBitwiseAnd(5, 7));
    
    return 0;
}
#endif