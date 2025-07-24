#ifndef SRC_MAIN_C
#define SRC_MAIN_C

#include "./lib/prelude.c"
#include "./lib/bytes.c"
#include "./sys/_.c"

uint sys_main(uint argc, list(string) argv) {
    
    // hey clang, how about you shut the fuck up?
    if (argc) if (argv) {}

    _target_writef_data wdata = {
        .in = {
            .fd = STDOUT_FD,
            .rbuff = "Hello world!" nl "\0",
            .nbytes_to_write = sizeof_buff(wdata.in.rbuff)
        }
    };
    _target_writef_fn(&wdata);

    return 0;
}
 
#endif //SRC_MAIN_C
