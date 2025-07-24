#include "targets/_requirements.c"
#ifdef SRC_SYS_ENTRY_C
    #error "Entry point included multiple times."
#else
#define SRC_SYS_ENTRY_C

#include "../main.c"
#include "../lib/bytes.c"

void sys_entry(uint argc, list(string) argv) __asm__ ("__sys_entry");
void sys_entry(uint argc, list(string) argv) {
    _target_writef_data wdata;

    _target_exit_data aexit = {.in = sys_main(argc, argv)};
    
    _target_exit_fn(&aexit);
    if (!aexit.out.isok) {
        wdata.in.fd = STDOUT_FD;
        wdata.in.nbytes_to_write = sizeof_buff(aexit.out.unwrap.err);
        wdata.in.rbuff = aexit.out.unwrap.err;
        _target_writef_fn(&wdata);
    }
}
 
#endif //SRC_SYS_ENTRY_C
