#ifdef SRC_SYS_ENTRY_C
    #error "Entry point included multiple times."
#else
#define SRC_SYS_ENTRY_C

void sys_entry() __asm__ ("__sys_entry");
void sys_entry() {

}
 
#endif //SRC_SYS_ENTRY_C
