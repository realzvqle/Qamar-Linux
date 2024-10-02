#include "dirio.h"
#include <dirent.h>




bool print_directory_content(char* path){
    if(path == NULL){
        path = ".";
    }
    DIR *dir = opendir(path);  
    if (dir == NULL) {
        perror("Unable to open directory");
        return false;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {  
        printf("%s\n", entry->d_name);  
    }

    closedir(dir);  


    return true;
}


bool create_directory(char* path){
    struct stat st = {0};

    if (stat(path, &st) == -1) {
        int result = mkdir(path, 0700); // will make it so the mode isn't always 0700
        if(!result) return false;
        return true;
    }
    return true;
}

bool remove_directory(char* path){
    struct stat st = {0};

    if (stat(path, &st) != -1) {
        int result = rmdir(path);
        if(result == -1) return false;
        return true;
    }
    else return false;
}