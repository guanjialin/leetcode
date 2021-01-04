//
// Created by addzero on 2020/12/18.
//


#ifdef __LOCAL__
#include "header.h"
#endif

char findTheDifference(char * s, char * t)
{
#ifdef __BIT__
    char ans = 0;

    while (*s != '\0') {
        ans = ans ^ *(s++) ^ *(t++);
    }
    ans ^= *t;

    return ans;
#else
    int ans = 0;
    while (*s != '\0') {
        ans = ans + *(t++) - *(s++) ;
    }
    ans += *t;
    return ans;
#endif
}

#ifdef __LOCAL__
int main()
{
    printf("%c\n", findTheDifference("abcd", "abcde"));
    
    return 0;
}
#endif