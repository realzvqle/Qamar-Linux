#include "startshell.h"



int main(int argc, char* argv[]){
    printf("\033[H\033[J");
    printf("Qamar Linux Build %f\n", VER);
    check_respective_shell_state(argv[1]);
    return 0;
}