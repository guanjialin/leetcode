//
// Created by addzero on 2020/12/8.
//


#ifdef __LOCAL__
#include "header.h"
#endif

char * interpret(char * command)
{
    int left = 0, right = 0, idx = 0;

    while (command[right] != '\0') {
        if ('G' == command[right]) {
            command[idx++] = 'G';
        } else if ('(' == command[right]) {
            left = right;
        } else if (')' == command[right]) {
            if (left == right - 1) {
                command[idx++] = 'o';
            } else {
                command[idx++] = 'a';
                command[idx++] = 'l';
            }
        }
        ++right;
    }
    command[idx] = '\0';

    return command;
}

#ifdef __LOCAL__
int main()
{
    char command[] = "G()(al)";
    printf("%s\n", interpret(command));
    
    return 0;
}
#endif