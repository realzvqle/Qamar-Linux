#include "processes.h"




int main(){
    printf("\033[H\033[J");
    printf("Qamar Init Build %f\n", VER);
    char *args[] = {"bin/shell", NULL};
    create_process(args);
    syscall(SYS_reboot,
            LINUX_REBOOT_MAGIC1, 
            LINUX_REBOOT_MAGIC2, 
            LINUX_REBOOT_CMD_POWER_OFF, NULL);

    return 0;
}