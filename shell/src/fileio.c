#include "fileio.h"





bool create_file(char* path){
    FILE* fp = fopen(path, "w");
    if(!fp){
        perror("fopen failed");
        return false;
    }
    fclose(fp);
    return true;
}


bool read_file(char* path){
    FILE* fp = fopen(path, "r");
    if(!fp){
        perror("fopen failed");
        return false;
    }
    char buffer[4096];

    while(fgets(buffer, 4096, fp)){
        printf("%s\n", buffer);
    }
    fclose(fp);
    return true;
}

bool write_file(char* args){
    char* path = strtok(args, " ");
    char* content = strtok(NULL, "\n");
    if(!path || !content){
        printf("Invalid Arguments\n");
        return false;
    }
    FILE* fp = fopen(path, "w");
    if(!fp){
        perror("fopen failed");
        return false;
    }
    fprintf(fp, "%s", content);
    fclose(fp);
    return true;
}