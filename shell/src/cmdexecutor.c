#include "cmdexecutor.h"
#include "dirio.h"
#include "fileio.h"




void execute_commands(int index, data* data){
    switch(index){
        case 0:
            if(!data->arg) break;
            printf("%s\n", data->arg);
            break;
        case 1:
            if(!data->arg) break;
            int result = chdir(data->arg);
            if(result == -1){
                perror("cd failed");
            }
            break;
        case 2:
            _exit(0);
            break;
        case 3:
            print_directory_content(data->arg);
            break;
        case 4:
            printf("\033[H\033[J");
            break;
        case 5:
            if(!data->arg) break;
            bool reslt = create_directory(data->arg);
            //if(!reslt) perror("Cannot Create Directory"); // will try to deal withthis later
            return;
        case 6:
            if(!data->arg) break;
            bool resslt = remove_directory(data->arg);
            if(!resslt) perror("Cannot Remove Directory");
            break;
        case 7:
            if(!data->arg) break;
            create_file(data->arg);
            break;
        case 8:
            if(!data->arg) break;
            write_file(data->arg);
            break;
        case 9:
            if(!data->arg) break;
            read_file(data->arg);
            break;
        default:
            printf("%s has been found, but no implemnation has been found\n", data->cmd);
            break;
    }
}