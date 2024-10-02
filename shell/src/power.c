#include "power.h"
#include <linux/reboot.h>




static inline void power_off(){
     syscall(SYS_reboot,
            LINUX_REBOOT_MAGIC1, 
            LINUX_REBOOT_MAGIC2, 
            LINUX_REBOOT_CMD_POWER_OFF, NULL);
}


static inline void reboot(){
     syscall(SYS_reboot,
            LINUX_REBOOT_MAGIC1, 
            LINUX_REBOOT_MAGIC2, 
            LINUX_REBOOT_CMD_RESTART, NULL);
}


void power_mgmt(char* cmd){
    if(strlen(cmd) < 2) return;
    switch(cmd[1]){
        case 'r':
            reboot();
            break;
        case 's':
            power_off();
            break;
        default:
            printf("Incorrect Argument\n");
            break;
    }
}


