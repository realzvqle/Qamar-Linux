#include "processes.h"
#include <sys/wait.h>



bool create_process(char* args[]){
    int pid = fork();  
    if (pid < 0) {
        perror("Fork failed");  
        return 1;
    }
    if (pid == 0) {  
        execv(args[0], args); 
        //perror("execv failed"); 
        return 1;
    } else {  
        int status;
        waitpid(pid, &status, 0);  

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            printf("Process exited with error status: %d\n", WEXITSTATUS(status));
            return false;
        } else {
            return true;
        }
    }
}