#include "processes.h"




int main(){
    printf("\033[H\033[J");
    printf("Qamar Init Build %f\n", VER);
    char *args[] = {"shell", NULL};
    
    while(1){
        create_process(args);
        printf("\nReturning to Shell....\n");      
    }

    return 0;
}