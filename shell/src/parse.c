#include "parse.h"




char** parse_str_to_argv(char* cmd, char* arg) {
    char* args[4096];  
    int argc = 0;
    
    char* token = strtok(arg, " ");
    while (token != NULL && argc < 4095) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }

    char** argv = malloc((argc + 2) * sizeof(char*));
    if (argv == NULL) {
        perror("malloc failed");
        return NULL;
    }

    argv[0] = cmd;

    for (int i = 0; i < argc; ++i) {
        argv[i + 1] = args[i];
    }

    argv[argc + 1] = NULL;

    return argv;  
}

