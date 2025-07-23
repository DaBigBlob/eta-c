#ifdef SRC_SYS_ENTRY_C
    #error "Entry point included multiple times."
#else
#define SRC_SYS_ENTRY_C

#include "../main.c"

void sys_entry() __asm__ ("__sys_entry");
void sys_entry() {
    //TODO call main
}
 
#endif //SRC_SYS_ENTRY_C
