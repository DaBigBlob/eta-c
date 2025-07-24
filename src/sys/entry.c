#include "targets/_requirements.c"
#ifdef SRC_SYS_ENTRY_C
    #error "Entry point included multiple times."
#else
#define SRC_SYS_ENTRY_C

#include "./_.c" // IWYU pragma: keep
#include "../main.c"
#include "../lib/bytes.c"

void sys_entry() __asm__ ("__sys_entry");
void sys_entry() {
    _target_writef_data wdata;
    _target_unpack_args_data aargs;
    _target_unpack_args_fn(&aargs);
    if (!aargs.out.isok) return; // TODO: do a better job: error handeling

    _target_exit_data aexit = {.in = sys_main(
        aargs.out.unwrap.ok.argc,
        aargs.out.unwrap.ok.argv
    )};
    _target_exit_fn(&aexit);
    if (!aexit.out.isok) {
        wdata.in.fd = STDOUT_FD;
        wdata.in.nbytes_to_write = sizeof_buff(aexit.out.unwrap.err);
        wdata.in.rbuff = aexit.out.unwrap.err;
        _target_writef_fn(&wdata);
    }
}
 
#endif //SRC_SYS_ENTRY_C
