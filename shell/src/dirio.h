#ifndef DIRIO_H_INCLUDED
#define DIRIO_H_INCLUDED





#include "shell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>





bool print_directory_content(char* path);
bool create_directory(char* path);
bool remove_directory(char* path);






#endif