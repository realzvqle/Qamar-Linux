#include "startshell.h"



int main(int argc, char* argv[]){
    sleep(1);
    printf("\nQamar Shell Build %f\n\n", VER);
    check_respective_shell_state(argv[1]);
    return 0;
}