

                                                

#ifndef SHELL_H_INCLUDED
#define SHELL_H_INCLUDED




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>


#define VER 0.000000
typedef struct _data{
    char* cmd;
    char* arg;
    bool shouldExit;
} data;







#endif