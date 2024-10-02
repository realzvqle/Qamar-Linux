#include "qminit.h"

#define VER 0.00000


int main(){
    printf("\033[H\033[J");
    printf("Qamar Linux Build %f\n", VER);
    char *args[] = {"shell", NULL};
    execv(args[0], args);
    printf("Shell Exited, Ending System\n");
    while(1){continue;}

    return 0;
}