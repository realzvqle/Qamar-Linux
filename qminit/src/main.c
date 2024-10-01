#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/syscall.h>


#define VER 0.00000


int main(){
    printf("\033[H\033[J");
    printf("Qamar Linux Build %f\n", VER);
    char *args[] = {"shell", NULL};
    execv(args[0], args);
    while(1){
        
    }
}