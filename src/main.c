#ifndef SRC_MAIN_C
#define SRC_MAIN_C

#include "./lib/prelude.c"
#include "./lib/bytes.c"
#include "./sys/_.c" // IWYU pragma: keep

uint sys_main(uint argc, list(string) argv) {

    if (argc < 2) return 2;

    _target_writef_data wdata = {
        .in = {
            .fd = STDOUT_FD,
            .rbuff = argv[1],
            .nbytes_to_write = sizeof_buff(argv[1])
        }
    };
    _target_writef_fn(&wdata);
    if (!wdata.out.isok) return 1;
    // TODO: better error handeling

    return 0;
}
 
#endif //SRC_MAIN_C
