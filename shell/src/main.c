#include "startshell.h"



int main(int argc, char* argv[]){
    sleep(1);
    printf("\nQamar Shell Build DEBUG\n\n");
    check_respective_shell_state(argv[1]);
    return 0;
}