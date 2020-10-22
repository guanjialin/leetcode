//
// Created by dell on 2020/10/21.
//

#include "header.h"

bool isLongPressedName(char * name, char * typed){
    char prev = 0;

    while (*typed != '\0') {
        if (*typed == *name) {
            prev = *name;
            ++typed;
            ++name;
        } else if (*typed == prev) {
            ++typed;
        } else {
            return false;
        }
    }

    return *name == '\0';
}

int main()
{
    printf("%d\n", isLongPressedName("alex", "aaleex"));
    printf("%d\n", isLongPressedName("saeed", "ssaaedd"));
    printf("%d\n", isLongPressedName("leelee", "lleeelee"));
    printf("%d\n", isLongPressedName("laiden", "laiden"));

    return 0;
}