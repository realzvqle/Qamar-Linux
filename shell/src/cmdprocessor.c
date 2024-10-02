#include "cmdprocessor.h"
#include "cmdexecutor.h"
#include "parse.h"
#include "processes.h"
#include <unistd.h>
#include <sys/wait.h>



static char* cmds[] = {"echo", "cd", "exit", "dir", "clear", "mkdir", 
                      "rmdir", "fcreate", "fwrite", "fread"};





void process_commands(data* data){
    int cmdSize = sizeof(cmds)/sizeof(cmds[0]);
    
    for(int i = 0; i < cmdSize; i++){
        if(strcmp(data->cmd, cmds[i]) == 0){
            execute_commands(i, data);
            return;
        }
    }
    
    char** argv = parse_str_to_argv(data->cmd, data->arg);

    int result = create_process(argv);
    if(result == 1) perror("create_process failed");
    free(argv);
}